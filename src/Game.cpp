// ^_~ Accepted
// All-Kill Automaton   RP++
// [AC] WA CE RE TLE MLE...
#define UNICODE
#define _UNICODE
#include "Game.h"

#include <graphics.h>
#include <windows.h>
#include <iostream>
#include <string>
#include <chrono>

#include "Draw.h"
#include "Event.h"
#include "Image.h"
#include "Init.h"
#include "Settings.h"
#include "Utils.h"
// #include "Python_Helper.h"
#include "Result.h"

int GameRun() {
    LoadImages();

    InitGame();

    Image_Try1();

    // Draw_Try1();

    ClearMsg();
    while (true) {
        auto start = hrc_now();

        int res_Event = Event();
        if (res_Event != 0) {
            EndBatchDraw();
            closegraph();
            return res_Event;
        }

        if (CheckWin()) {
            Win();
        }

        FlushBatchDraw();

        auto end = hrc_now();
        unsigned long long diff = diff_time(start, end);
        if (diff < 1000 / FPS) {
            Sleep(1000 / FPS - diff);
        }
    }
    EndBatchDraw();
    closegraph();
    return 0;
}
