#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#define SCRIPT_VERSION "1.0 [ Build Settings Graphics and Fps for PUBG ]"

// Cek keberadaan folder atau file
int cek_eksistensi(const char *path) {
    struct stat buffer;
    return (stat(path, &buffer) == 0);
}

// Menampilkan notifikasi
void shell(const char *message, int fps) {
    char command[512];
    snprintf(command, sizeof(command),
             "cmd notification post -S bigtext -t '♨️ Graphics for PUBG' 'Tag' '%s %d Hz' > /dev/null 2>&1",
             message, fps);
    system(command);
}

// Fungsi untuk mengatur FPS berdasarkan mode
void setFps(const char *mode, const char *folder, int fps) {
    if (!cek_eksistensi("/sdcard/pidof/Include")) {
        printf("⚠️ Folder sumber tidak ditemukan!\n");
        return;
    }
    
    system("cp -r /sdcard/pidof/Include/file /sdcard/Android/data/com.tencent.ig > /dev/null 2>&1");
    system("cmd package compile -m quicken -f com.tencent.ig > /dev/null 2>&1");
    system("cmd deviceidle except-idle-whitelist +com.tencent.ig > /dev/null 2>&1");
    system("cmd activity kill-all");
    system("cmd activity clear-debug-app");
    system("cmd activity clear-exit-info");
    system("cmd activity clear-watch-heap com.tencent.ig");
    system("cmd activity set-watch-heap com.tencent.ig 52000000");

    char path[256];
    snprintf(path, sizeof(path), "/sdcard/pidof/%s", folder);
    
    if (!cek_eksistensi(path)) {
        printf("⚠️ Folder %s tidak ditemukan!\n", folder);
        return;
    }

    char command[512];
    snprintf(command, sizeof(command), 
             "cp -r /sdcard/pidof/%s/%d/file /sdcard/Android/data/com.tencent.ig > /dev/null 2>&1", 
             folder, fps);
    system(command);

    shell(mode, fps);
    printf("[CRITICAL WARNING] Script ini HARUS dijalankan sebelum memainkan PUBG.\n");
    printf("                   Jika tidak, sistem grafis mungkin gagal, menyebabkan crash atau lag.\n");
    printf("                   Hanya kompatibel dengan PUBG Mobile versi 3.7.0.\n");
    printf("\n");
    printf("[CRITICAL WARNING] This script MUST be executed before launching PUBG.\n");
    printf("                   Failure to do so may result in graphical errors, crashes, or severe lag.\n");
    printf("                   Compatible only with PUBG Mobile version 3.7.0.\n");
}

void Usage() {
    printf("GFP %s - PUBG Graphics and FPS Optimization Utility\n", SCRIPT_VERSION);
    printf("Usage: GFP [OPTION] [FPS]\n\n");    
    printf("Options:\n");
    printf("  -H [FPS]     Set HDR Graphics mode (choose: 60, 90, or 120 Hz)\n");
    printf("  -S [FPS]     Set Semooth Graphics mode (choose: 60, 90, or 120 Hz)\n");
    printf("  -h, --help   Display this help message and exit\n\n");
    printf("Description:\n");
    printf("  GFP is a lightweight system optimization tool designed to\n");
    printf("  enhance the graphics settings and frame rate of PUBG Mobile.\n");
    printf("  It dynamically configures the graphics mode (HDR or Smooth) and\n");
    printf("  adjusts the FPS to match the selected refresh rate.\n\n");
    printf("Examples:\n");
    printf("  Set HDR Graphics to 90 FPS:\n");
    printf("      GFP -H 90\n\n");
    printf("  Set Smooth Graphics to 120 FPS:\n");
    printf("      GFP -S 120\n\n");
    printf("System Requirements:\n");
    printf("  - Device must have access to the necessary configuration files\n");
    printf("  - Root access **may** be required depending on the Android version\n");
    printf("  - PUBG Mobile must be installed in the default directory\n\n");
    printf("For more information, visit:\n");
    printf("  PUBG Mobile Optimization Guide: https://www.pubgmobile.com/en/\n");
    printf("  Android Debugging Guide:  https://developer.android.com/studio/command-line/adb\n\n");
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
   if (argc != 3) {
        Usage();
    }

    int selectedFps = atoi(argv[2]);
    if (selectedFps != 60 && selectedFps != 90 && selectedFps != 120) {
        printf("[ERROR] Invalid FPS value! Use 60, 90, or 120.\n");
        return EXIT_FAILURE;
    }

    if (strcmp(argv[1], "-H") == 0) {
        setFps("Successfully set HDR Graphics PUBG at", "HDR", selectedFps);
    } else if (strcmp(argv[1], "-S") == 0) {
        setFps("Successfully set Semooth Graphics PUBG at", "Semooth", selectedFps);
    } else if (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0) {
        Usage();
    } else {
        printf("[ERROR] Unknown option: %s\n", argv[1]);
        Usage();
    }
        
    sleep(1);
    printf("\n");
    printf(" ⚠️ Modul ini dilindungi hak cipta dan\n");
    printf(" hanya untuk penggunaan oleh pengguna biasa.\n");
    printf(" Setiap penggunaan kode, desain, atau fitur\n");
    printf(" oleh pengembang lain tanpa izin tertulis dari\n");
    printf(" pemilik hak cipta sangat dilarang.\n");
    printf("______________________________________________(+)\n\n");

    return 0;
}