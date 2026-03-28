// ^_～ Initialized
// All-Kill Automaton   Debug++
// [RUN] BUILD MAP SPAWN PLAYER...

#include "Event.h"

#include "Settings.h"
#include "Utils.h"
#include "Update.h"

int Event() {
    ExMessage msg;

    while (peekmessage(&msg)) {
        if (msg.vkcode == VK_RETURN) {
            return 1;
        }
        if (msg.vkcode == 'T') {
            if (Window_Width * Window_Height > 1 && CntBoom >= 1 && CntBoom < Window_Width * Window_Height) {
                return 4;
            }
        }
        if (setting) {
            if (msg.message == WM_LBUTTONDOWN) {
                int x = msg.x;
                int y = msg.y;
                Click(x, y);
            }
            if (msg.message == WM_KEYUP) {
                if ('0' <= msg.vkcode && msg.vkcode <= '9') {
                    Enter(msg.vkcode - '0');
                } else if (msg.vkcode == VK_BACK) {
                    BackSpace();
                }
            }

            continue;
        }
        if (msg.vkcode == 'S') {
            return 3;
        }
        if (End) {
            continue;
        }
        if (msg.message == WM_LBUTTONDOWN) {
            if (msg.x < Border_Size || Border_Size + Window_Width * Square_Size <= msg.x ||
                msg.y < Border_Size || Border_Size + Window_Height * Square_Size <= msg.y) {
                continue;
            }
            int x = (msg.x - Border_Size) / Square_Size;
            int y = (msg.y - Border_Size) / Square_Size;
            bool res_OpenSquare = OpenSquare(x, y);
            if (res_OpenSquare) {
                SleepMs(1000);
                return 2;
            }
        }
        if (msg.message == WM_RBUTTONDOWN) {
            if (msg.x < Border_Size || Border_Size + Window_Width * Square_Size <= msg.x ||
                msg.y < Border_Size || Border_Size + Window_Height * Square_Size <= msg.y) {
                continue;
            }
            int x = (msg.x - Border_Size) / Square_Size;
            int y = (msg.y - Border_Size) / Square_Size;
            Add_Flag(x, y);
        }
    }
    return 0;
}
