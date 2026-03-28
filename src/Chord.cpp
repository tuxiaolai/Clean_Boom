// ^_~ Accepted
// All-Kill Automaton   RP++
// [AC] WA CE RE TLE MLE...

#include "Chord.h"

#include "Board.h"
#include "Settings.h"
#include "Utils.h"
#include "Update.h"

bool Chord_Open_Square(int x, int y) {
    if (!OpenChord) {
        return false;
    }
    if (squares[x][y] < 1 || 8 < squares[x][y]) {
        return false;
    }
    int cnt = 0;
    for (int i = 0; i < 8; i++) {
        int nx = x + way8[i][0];
        int ny = y + way8[i][1];
        if (nx < 0 || Window_Width <= nx || ny < 0 || Window_Height <= ny) {
            continue;
        }
        if (Have_Flag[nx][ny]) {
            cnt++;
        }
    }
    if (cnt == squares[x][y]) {
        for (int i = 0; i < 8; i++) {
            int nx = x + way8[i][0];
            int ny = y + way8[i][1];
            if (nx < 0 || Window_Width <= nx || ny < 0 || Window_Height <= ny) {
                continue;
            }
            if ((squares[nx][ny] == Closed || squares[nx][ny] == Boom) && !Have_Flag[nx][ny]) {
                if (OpenSquare(nx, ny)) {
                    return true;
                }
            }
        }
    }
    return false;
}

void Chord_Add_Flag(int x, int y) {
    if (!FlagChord) {
        return;
    }
    if (squares[x][y] < 1 || 8 < squares[x][y]) {
        return;
    }
    int cnt = 8;
    for (int i = 0; i < 8; i++) {
        int nx = x + way8[i][0];
        int ny = y + way8[i][1];
        if (nx < 0 || Window_Width <= nx || ny < 0 || Window_Height <= ny) {
            cnt--;
            continue;
        }
        if (squares[nx][ny] != Closed && squares[nx][ny] != Boom) {
            cnt--;
        }
    }
    if (cnt == squares[x][y]) {
        for (int i = 0; i < 8; i++) {
            int nx = x + way8[i][0];
            int ny = y + way8[i][1];
            if (nx < 0 || Window_Width <= nx || ny < 0 || Window_Height <= ny) {
                continue;
            }
            if ((squares[nx][ny] == Closed || squares[nx][ny] == Boom) && !Have_Flag[nx][ny]) {
                Add_Flag(nx, ny);
            }
        }
    }
}
