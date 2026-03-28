// ^_～ Initialized
// All-Kill Automaton   Debug++
// [RUN] BUILD MAP SPAWN PLAYER...


#ifndef CLEAN_BOOM_IMAGE_H
#define CLEAN_BOOM_IMAGE_H

#include <array>
#include <easyx.h>
#include <string>

inline std::array<IMAGE, 17> imgs20;
inline std::array<IMAGE, 14> imgs50;

void LoadImage_t(const std::wstring &File, IMAGE* i);

void LoadImages();

void Image_Try1();

#endif
