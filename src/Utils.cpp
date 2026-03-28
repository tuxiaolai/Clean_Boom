// ^_～ Initialized
// All-Kill Automaton   Debug++
// [RUN] BUILD MAP SPAWN PLAYER...

#include "Utils.h"

#include <easyx.h>

time_point_sc hrc_now() {
    return std::chrono::high_resolution_clock::now();
}

unsigned long long diff_time(time_point_sc start, time_point_sc end) {
    return std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
}

void SleepMs(unsigned long milliseconds) {
    std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
}

void ClearMsg() {
    ExMessage msg;
    while (peekmessage(&msg));
}
