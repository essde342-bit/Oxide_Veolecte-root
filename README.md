# Oxide Survival Cheat — Root Module

## Установка
1. Скачай oxide-cheat-module.zip из Actions → Artifacts
2. Magisk → Modules → Install from storage
3. Выбери ZIP
4. Settings → Zygisk ✅
5. Reboot
6. Запусти игру → подожди 5 сек → меню появится

## Требования
- Android 8+
- Magisk 24+ с Zygisk
- arm64 устройство

## Логи
adb logcat | grep -E "OxideCheat|OxideZygisk|A64_HOOK"

## Компоненты
- Zygisk API v5 (официальный от topjohnwu)
- And64InlineHook (проверенная ARM64 библиотека)
- OpenGL ES 3 рендерер
