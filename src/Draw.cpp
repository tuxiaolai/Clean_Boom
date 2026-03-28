// ^_~ Accepted
// All-Kill Automaton   RP++
// [AC] WA CE RE TLE MLE...

#include "Draw.h"

#include "Board.h"
#include "Image.h"
#include "Settings.h"
#include "Utils.h"

void InitDraw() {
    for (int i = 0; i < Window_Width; i++) {
        for (int j = 0; j < Window_Height; j++) {
            if (Square_Size==20) {
                putimage(Border_Size + i * Square_Size, Border_Size + j * Square_Size, &imgs20[Closed]);
            }else if (Square_Size==50) {
                putimage(Border_Size + i * Square_Size, Border_Size + j * Square_Size, &imgs50[Closed]);
            }
        }
        SleepMs(1);
        FlushBatchDraw();
    }
}

void Draw_Try1() {
    for (int i = 0; i < Window_Width; i++) {
        for (int j = 0; j < Window_Height; j++) {
            if (squares[i][j] == Boom) {
                if (Square_Size==20) {
                    putimage(Border_Size + i * Square_Size, Border_Size + j * Square_Size, &imgs20[Boom]);
                }else if (Square_Size==50) {
                    putimage(Border_Size + i * Square_Size, Border_Size + j * Square_Size, &imgs50[Boom]);
                }
            }
        }
    }
}

void Draw_Square(int x, int y, int type) {
    if (Square_Size==20) {
        putimage(Border_Size + x * Square_Size, Border_Size + y * Square_Size, &imgs20[type]);
    }else if (Square_Size==50) {
        putimage(Border_Size + x * Square_Size, Border_Size + y * Square_Size, &imgs50[type]);
    }
}
