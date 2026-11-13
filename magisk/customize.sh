SKIPUNZIP=1

ui_print "================================"
ui_print "  Oxide Survival Cheat v1.0"
ui_print "================================"

if [ "$(magisk -V)" -lt 24000 ]; then
    ui_print "! Magisk 24.0+ required"
    abort
fi

unzip -o "$ZIPFILE" -x 'META-INF/*' -d "$MODPATH" >&2

mkdir -p "$MODPATH/lib"

if [ -f "$MODPATH/liboxide_cheat.so" ]; then
    mv "$MODPATH/liboxide_cheat.so" "$MODPATH/lib/"
fi

set_perm_recursive "$MODPATH" 0 0 0755 0644
set_perm "$MODPATH/lib/liboxide_cheat.so" 0 0 0755

if [ -f "$MODPATH/zygisk/arm64-v8a.so" ]; then
    set_perm "$MODPATH/zygisk/arm64-v8a.so" 0 0 0755
fi

ui_print "- Done! Enable Zygisk and reboot."
