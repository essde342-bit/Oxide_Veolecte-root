LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)
LOCAL_MODULE := oxide_zygisk
LOCAL_SRC_FILES := zygisk.cpp
LOCAL_LDLIBS := -llog
LOCAL_CFLAGS := -std=c++17 -O2 -fvisibility=hidden
include $(BUILD_SHARED_LIBRARY)
