#!/system/bin/sh
# Checking ID shell
if [ "$(id -u)" -ne 2000 ]; then
    echo "[ Error |@UnixeID(Yeye)]"
    exit 1
fi
# Smart Notification
shell() {
    sor="$1"
    cmd notification post -S bigtext -t '♨️ Graphics For PUBG' 'Tag' "$sor" > /dev/null 2>&1
}
# Style display Terminal
    echo
    echo "     ☆================================☆"
    echo
    echo "       ~ Description. Graphics For PUBG.... "
    echo
    echo "       - Author                 :  @UnixeID"
    echo "       - Version                :  1.0"
    echo "       - Release               :  07 - Mar - 2025"
    echo "       - Name Shell         :  Graphics For PUBG."
    echo
    echo "    |_______________________________________|"
    echo "    \______________________________________/"
    echo
    echo "   Priority Graphics For PUBG "
    sleep 2
    echo
    echo
        rm -rf /data/local/tmp/*
        cp /sdcard/pidof/sync /data/local/tmp
        chmod +x /data/local/tmp/sync
        # Pilihan mode
            if [ "$1" = "-H" ]; then
             shell "Applying Graphics For PUBG HDR, please wait 1-3 seconds..."
             /data/local/tmp/sync -H "$2"
           elif [ "$1" = "-S" ]; then
               shell "Applying Graphics For PUBG Smooth, please wait 1-3 seconds..."
           /data/local/tmp/sync -S "$2"
           elif [ "$1" = "--help" ]; then
          /data/local/tmp/sync --help
        else
            echo "Usage: ./run.sh [-H|-S|--help] [60|90|120]"
            fi