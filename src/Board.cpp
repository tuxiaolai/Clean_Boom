// ^_～ Initialized
// All-Kill Automaton   Debug++
// [RUN] BUILD MAP SPAWN PLAYER...


#include "Board.h"

#include "Settings.h"

#include <algorithm>
#include <random>

std::vector<std::vector<int> > squares(Window_Width, std::vector(Window_Height, 0));
std::vector<std::vector<bool> > Have_Flag(Window_Width, std::vector(Window_Height, false));


void InitBoard() {
    // squares.resize(Window_Width, std::vector<int>(Window_Height, 0));
    // Have_Flag.resize(Window_Width, std::vector<bool>(Window_Height, false));
    squares.resize(Window_Width);
    for (int i = 0; i < Window_Width; i++) {
        squares[i].resize(Window_Height);
    }
    Have_Flag.resize(Window_Width);
    for (int i = 0; i < Window_Width; i++) {
        Have_Flag[i].resize(Window_Height);
    }
    squares.shrink_to_fit();
    Have_Flag.shrink_to_fit();
    for (int i = 0; i < Window_Width; i++) {
        for (int j = 0; j < Window_Height; j++) {
            squares[i][j] = Closed;
            Have_Flag[i][j] = false;
        }
    }
}

struct Node_Board {
    int x, y;
};

std::random_device rd;
std::mt19937 g(rd());

inline std::vector<Node_Board> nodes(Window_Width * Window_Height);

void InitBoom() {
    nodes.resize(Window_Width * Window_Height);
    nodes.shrink_to_fit();
    for (int i = 0; i < Window_Width; i++) {
        for (int j = 0; j < Window_Height; j++) {
            nodes[i * Window_Height + j] = {i, j};
        }
    }
    std::shuffle(nodes.begin(), nodes.end(), g);
    for (int i = 0; i < CntBoom; i++) {
        int x = nodes[i].x, y = nodes[i].y;
        squares[x][y] = Boom;
    }
}
