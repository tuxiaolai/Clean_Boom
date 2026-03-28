// ^_~ Accepted
// All-Kill Automaton   RP++
// [AC] WA CE RE TLE MLE...

#include "Settings.h"

#include <graphics.h>
#include <iostream>
#include <ostream>

#include "Image.h"
// #include "Python_Helper.h"
#include "Event.h"
#include "Utils.h"

void DrawSetting() {
    setbkcolor(RGB(0x0E, 0x1D, 0x69)); //背景颜色
    cleardevice();

    putimage(10, 40, &imgs20[16]);

    //30 30   180 80
    putimage(30, 30, &imgs50[Window_Width / 100 % 10]);
    putimage(80, 30, &imgs50[Window_Width / 10 % 10]);
    putimage(130, 30, &imgs50[Window_Width % 10]);

    //230 30   380 80
    putimage(230, 30, &imgs50[Window_Height / 100 % 10]);
    putimage(280, 30, &imgs50[Window_Height / 10 % 10]);
    putimage(330, 30, &imgs50[Window_Height % 10]);

    //30 110   280 160
    putimage(30, 110, &imgs50[CntBoom / 1000 % 10]);
    putimage(80, 110, &imgs50[CntBoom / 100 % 10]);
    putimage(130, 110, &imgs50[CntBoom / 10 % 10]);
    putimage(180, 110, &imgs50[CntBoom % 10]);

    putimage(230, 110, &imgs50[Boom]);

    putimage(203, 200, &imgs50[Closed + (Flag - Closed) * (Square_Size == 20)]);
    putimage(283, 200, &imgs50[Closed + (Flag - Closed) * (Square_Size == 50)]);
    putimage(383, 200, &imgs50[Closed + (Flag - Closed) * OpenChord]);
    putimage(497, 200, &imgs50[Closed + (Flag - Closed) * FlagChord]);

    if (focus == 1) {
        setlinecolor(RGB(0x9D, 0x3D, 0xDF));
        line(30, 80, 180, 80);
    } else if (focus == 2) {
        setlinecolor(RGB(0x9D, 0x3D, 0xDF));
        line(230, 80, 380, 80);
    } else if (focus == 3) {
        setlinecolor(RGB(0x9D, 0x3D, 0xDF));
        line(30, 160, 280, 160);
    }
    FlushBatchDraw();
}

void Click(int x, int y) {
    if (30 <= x && x <= 180 && 30 <= y && y <= 80) {
        focus = 1;
    } else if (230 <= x && x <= 380 && 30 <= y && y <= 80) {
        focus = 2;
    } else if (30 <= x && x <= 280 && 110 <= y && y <= 160) {
        focus = 3;
    } else {
        if (203 <= x && x <= 253 && 200 <= y && y <= 250) {
            Square_Size = 20;
        } else if (283 <= x && x <= 323 && 200 <= y && y <= 250) {
            Square_Size = 50;
        } else if (383 <= x && x <= 423 && 200 <= y && y <= 250) {
            OpenChord ^= 1;
        } else if (497 <= x && x <= 547 && 200 <= y && y <= 250) {
            FlagChord ^= 1;
        }
        focus = 0;
    }
}

void Enter(int val) {
    if (focus == 1) {
        Window_Width = std::min(999, Window_Width * 10 + val);
    } else if (focus == 2) {
        Window_Height = std::min(999, Window_Height * 10 + val);
    } else if (focus == 3) {
        CntBoom = std::min(9999, CntBoom * 10 + val);
    }
}

void BackSpace() {
    if (focus == 1) {
        Window_Width /= 10;
    } else if (focus == 2) {
        Window_Height /= 10;
    } else if (focus == 3) {
        CntBoom /= 10;
    }
}

int Setting() {
    // int res_Python_Helper = Python_Helper(20);
    // std::cout << "Python_Helper return " << res_Python_Helper << std::endl;
    //
    // res_Python_Helper = Python_Helper(60/*Square_Size*/);
    // std::cout << "Python_Helper return " << res_Python_Helper << std::endl;

    setting = true;

    initgraph(650, 400);

    BeginBatchDraw();

    ClearMsg();
    while (true) {
        auto start = hrc_now();

        DrawSetting();

        int res_Event = Event();
        if (res_Event != 0) {
            EndBatchDraw();
            closegraph();
            setting = false;
            return res_Event;
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

    setting = false;
    return 0;
}
