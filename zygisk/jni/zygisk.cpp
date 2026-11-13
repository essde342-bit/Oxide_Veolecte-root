#include <cstdlib>
#include <unistd.h>
#include <dlfcn.h>
#include <cstring>
#include <android/log.h>
#include "zygisk.hpp"

using zygisk::Api;
using zygisk::AppSpecializeArgs;

#define LOG_TAG "OxideZygisk"
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)

#define TARGET_PKG "com.rust.oxidesurvival"
#define CHEAT_LIB "/data/adb/modules/oxide_cheat/lib/liboxide_cheat.so"

class OxideModule : public zygisk::ModuleBase {
public:
    void onLoad(Api *api, JNIEnv *env) override {
        this->api = api;
        this->env = env;
    }

    void preAppSpecialize(AppSpecializeArgs *args) override {
        const char *process = env->GetStringUTFChars(args->nice_name, nullptr);
        if (process && strcmp(process, TARGET_PKG) == 0) {
            isTarget = true;
            LOGI("Target detected: %s", process);
        }
        if (process) env->ReleaseStringUTFChars(args->nice_name, process);
    }

    void postAppSpecialize(const AppSpecializeArgs *) override {
        if (!isTarget) return;
        LOGI("Loading cheat library...");
        sleep(3);
        void *handle = dlopen(CHEAT_LIB, RTLD_NOW);
        if (!handle) {
            LOGE("dlopen failed: %s", dlerror());
            return;
        }
        LOGI("Cheat loaded OK");
    }

private:
    Api *api = nullptr;
    JNIEnv *env = nullptr;
    bool isTarget = false;
};

REGISTER_ZYGISK_MODULE(OxideModule)
