// ^_～ Initialized
// All-Kill Automaton   Debug++
// [RUN] BUILD MAP SPAWN PLAYER...

#define UNICODE
#define _UNICODE

#include <iostream>

#include "Game.h"
#include "Image.h"
#include "Settings.h"
#include "Utils.h"

int main() {
    LoadImages();
    int res_Setting = Setting();
    if (res_Setting == 1) {
        return 0;
    }
    while (true) {
        int res_GameRun = GameRun();
        if (res_GameRun == 1) {
            // std::cout<<"Break!"<<std::endl;
            break;
        }
        if (res_GameRun == 3) {
            int res_Setting = Setting();
            if (res_Setting == 1) {
                break;
            }
        }
        ClearMsg();
    }
    // std::cout<<"Return 0;"<<std::endl;
    return 0;
}
