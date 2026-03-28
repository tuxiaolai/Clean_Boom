// ^_～ Initialized
// All-Kill Automaton   Debug++
// [RUN] BUILD MAP SPAWN PLAYER...
#define UNICODE
#define _UNICODE

#include "Image.h"

#include <iostream>

#include "Settings.h"
#include "Utils.h"


void LoadImage_t(const std::wstring &File, IMAGE *i) {
    int res = loadimage(i, File.c_str());
    if (res) {
        std::wcerr << "[ERROR] Failed to load image: "
                << File << std::endl;
    }
}

void LoadImages() {
    for (int i = 0; i <= 13; i++) {
        LoadImage_t(_T("Image/img20/Img") + std::to_wstring(i) + _T(".png"), &imgs20[i]);
        LoadImage_t(_T("Image/img50/Img") + std::to_wstring(i) + _T(".png"), &imgs50[i]);
    }
    LoadImage_t(_T("Image/img20/ImgWin.png"), &imgs20[14]);
    LoadImage_t(_T("Image/img20/ImgLose.png"), &imgs20[15]);
    LoadImage_t(_T("Image/img20/Setting.png"), &imgs20[16]);
}

std::array<int, 12> Imglist1 = {{12, 1, 2, 3, 4, 5, 6, 7, 8, 10, 11, 13}};

void Image_Try1() {
    for (int i = 0; i < 12; i++) {
        int x = Border_Size + i * Square_Size, y = Border_Size + Window_Height * Square_Size + 10;
        if (Square_Size == 20) {
            putimage(x, y, &imgs20[Imglist1[i]]);
        } else if (Square_Size == 50) {
            putimage(x, y, &imgs50[Imglist1[i]]);
        }
        SleepMs(1);
        FlushBatchDraw();
    }
}
