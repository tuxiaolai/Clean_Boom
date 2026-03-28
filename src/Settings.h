// ^_～ Initialized
// All-Kill Automaton   Debug++
// [RUN] BUILD MAP SPAWN PLAYER...


#ifndef CLEAN_BOOM_SETTINGS_H
#define CLEAN_BOOM_SETTINGS_H

#include <graphics.h>

inline int FPS = 60;
inline int Window_Width = 70, Window_Height = 40, Square_Size = 20, Border_Size = 5; //1-100 1-100 5-150
inline int CntBoom = 420; //1-9999
inline bool FlagChord = false, OpenChord = true;

const COLORREF BKCOLOR = RGB(0xf5, 0xf5, 0xf5);

const int Closed = 0x0C, Null = 0x0A, Flag = 0x0D, Boom = 0x0B;

inline bool setting = false;

inline int focus = 0;

void Click(int x, int y);

void Enter(int val);

void BackSpace();

int Setting();


#endif //CLEAN_BOOM_SETTINGS_H
