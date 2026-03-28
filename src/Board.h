// ^_～ Initialized
// All-Kill Automaton   Debug++
// [RUN] BUILD MAP SPAWN PLAYER...


#ifndef CLEAN_BOOM_BOARD_H
#define CLEAN_BOOM_BOARD_H

#include <vector>

extern std::vector<std::vector<int> > squares;
extern std::vector<std::vector<bool> > Have_Flag;

void InitBoard();

void InitBoom();
#endif //CLEAN_BOOM_BOARD_H
