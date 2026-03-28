// ^_～ Initialized
// All-Kill Automaton   Debug++
// [RUN] BUILD MAP SPAWN PLAYER...

#ifndef CLEAN_BOOM_UTILS_H
#define CLEAN_BOOM_UTILS_H

#include <array>
#include <chrono>
#include <thread>

typedef std::chrono::time_point<std::chrono::system_clock> time_point_sc;

time_point_sc hrc_now();

unsigned long long diff_time(time_point_sc start, time_point_sc end);

void SleepMs(unsigned long milliseconds);

void ClearMsg();

inline std::array<std::array<int, 2>, 8> way8 = {{{-1, -1}, {0, -1}, {1, -1}, {-1, 0}, {1, 0}, {-1, 1}, {0, 1}, {1, 1}}};

#endif //CLEAN_BOOM_UTILS_H
