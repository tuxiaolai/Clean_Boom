// ^_~ Accepted
// All-Kill Automaton   RP++
// [AC] WA CE RE TLE MLE...

#include "Update.h"

#include <array>
#include <queue>

#include "Board.h"
#include "Settings.h"
#include "Draw.h"
#include "Utils.h"
#include "Result.h"
#include "Chord.h"

int cntbooms(int x, int y) {
    int res = 0;
    for (int i = 0; i < 8; i++) {
        int nx = x + way8[i][0];
        int ny = y + way8[i][1];
        if (nx < 0 || Window_Width <= nx || ny < 0 || Window_Height <= ny) {
            continue;
        }
        if (squares[nx][ny] == Boom) {
            res++;
        }
    }
    return res;
}

struct Node_Update {
    int x = 0, y = 0, t = 0;
};

bool OpenSquare(int x, int y) {
    if (Have_Flag[x][y]) {
        return false;
    }
    if (squares[x][y] == Boom) {
        Draw_Try1();
        FlushBatchDraw();
        Lose();
        return false;
    }
    if (squares[x][y] != Closed) {
        Chord_Add_Flag(x,y);
        return Chord_Open_Square(x,y);
    }

    //BFS
    int t = 0;

    std::queue<Node_Update> q;
    int cnt = cntbooms(x, y);
    if (cnt == 0) {
        squares[x][y] = Null;
        Draw_Square(x, y, Null);
        q.push(Node_Update{x, y, 0});
    } else {
        squares[x][y] = cnt;
        Draw_Square(x, y, cnt);
        CntOpen++;
    }
    while (q.size()) {
        Node_Update u = q.front();
        if (q.size()) {
            q.pop();
        }
        CntOpen++;
        if (u.t > t) {
            FlushBatchDraw();
            SleepMs(50);
            t++;
        }
        for (int i = 0; i < 8; i++) {
            int nx = u.x + way8[i][0];
            int ny = u.y + way8[i][1];
            if (nx < 0 || Window_Width <= nx || ny < 0 || Window_Height <= ny) {
                continue;
            }
            if (squares[nx][ny] != Closed) {
                continue;
            }
            cnt = cntbooms(nx, ny);
            if (cnt == 0) {
                squares[nx][ny] = Null;
                Draw_Square(nx, ny, Null);
                q.push(Node_Update{nx, ny, u.t + 1});
            } else {
                squares[nx][ny] = cnt;
                Draw_Square(nx, ny, cnt);
                CntOpen++;
            }
        }
    }
    FlushBatchDraw();
    return false;
}

void Add_Flag(int x, int y) {
    if (squares[x][y] != Closed && squares[x][y] != Boom) {
        // Chord_Add_Flag(x,y);
        return;
    }
    if (Have_Flag[x][y] == true) {
        Have_Flag[x][y] = false;
        Draw_Square(x, y, Closed);
        if (squares[x][y] == Boom) {
            RightFlag--;
        } else {
            WrongFlag--;
        }
    } else {
        Have_Flag[x][y] = true;
        Draw_Square(x, y, Flag);
        if (squares[x][y] == Boom) {
            RightFlag++;
        } else {
            WrongFlag++;
        }
    }
    FlushBatchDraw();
}
