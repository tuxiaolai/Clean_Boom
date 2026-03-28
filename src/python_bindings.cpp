#include <pybind11/pybind11.h>
#include "Game.h"
#include "Image.h"
#include "Settings.h"
#include "Utils.h"

int pb_Init() {
    LoadImages();
    int res_Setting = Setting();
    if (res_Setting == 1) {
        return 1;
    }
    return 0;
}

int pb_Frame() {
    int res_GameRun = GameRun();
    if (res_GameRun == 1) {
        return 1;
    }
    if (res_GameRun == 3) {
        int res_Setting = Setting();
        if (res_Setting == 1) {
            return 1;
        }
    }
    ClearMsg();
    return 0;
}

PYBIND11_MODULE(tuxiaolai_Clean_Boom_cpp, m) {
    m.doc() = "A module wrapping Clean Boom game logic for Python";

    m.def("pb_Init", &pb_Init, "Initialize the game resources and settings. Returns 0 on success, 1 on exit/quit.");
    m.def("pb_Frame", &pb_Frame, "Execute one frame of game logic. Returns 0 to continue, 1 to end game.");
}