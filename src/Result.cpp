// ^_~ Accepted
// All-Kill Automaton   RP++
// [AC] WA CE RE TLE MLE...

#include "Result.h"

#include <iostream>
#include <ostream>

#include "Image.h"
#include "Settings.h"
#include "Update.h"
#include "Utils.h"

bool CheckWin() {
    return (RightFlag == CntBoom && WrongFlag == 0) || CntOpen == Window_Width * Window_Height - CntBoom;
}

void Win() {
    std::cout << "Win" << std::endl;
    putimage(Border_Size + Square_Size * 12, Border_Size + Square_Size * Window_Height, &imgs20[14]);
    End=true;
}

void Lose() {
    std::cout << "Lose" << std::endl;
    putimage(Border_Size + Square_Size * 12, Border_Size + Square_Size * Window_Height, &imgs20[15]);
    End=true;
}
