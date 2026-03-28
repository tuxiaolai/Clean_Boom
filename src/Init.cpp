// ^_～ Initialized
// All-Kill Automaton   Debug++
// [RUN] BUILD MAP SPAWN PLAYER...

#include "Init.h"

#include <easyx.h>

#include "Settings.h"
#include "Board.h"
#include "Draw.h"
#include "Image.h"
#include "Result.h"
#include "Update.h"

void InitGame() {
    initgraph(Window_Width * Square_Size + Border_Size * 2,
              Window_Height * Square_Size + Border_Size * 2 + 30 + Square_Size,EX_NOCLOSE);
    BeginBatchDraw();

    setbkcolor(BKCOLOR); //背景颜色
    cleardevice();

    CntOpen = 0;
    RightFlag = 0;
    WrongFlag = 0;
    End = false;

    InitBoard();
    InitDraw();
    InitBoom();
}
