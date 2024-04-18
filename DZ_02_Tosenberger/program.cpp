#include "game_of_life.h"
#include <iostream>

void GameOfLife::SetBoard() {
    for (int j = 0; j < 20; j++) {
        for (int k = 0; k < 20; k++) {
            if (rand() % 10 < 3) {
                boardSize[k][j] = true;
            }
        }
    }
}

void GameOfLife::TestAlive(int x, int y) {
    alivecnt = 0;

    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) continue; // Skip the current cell
            int neighborX = x + i;
            int neighborY = y + j;
            if (neighborX >= 0 && neighborX < 20 && neighborY >= 0 && neighborY < 20 &&
                boardSize[neighborX][neighborY]) {
                alivecnt++;
            }
        }
    }

    if (alivecnt < 2 || alivecnt > 3) {
        boardSizetemp[x][y] = false;
    }
    else if (alivecnt == 3 && !boardSize[x][y]) {
        boardSizetemp[x][y] = true;
    }
    else {
        boardSizetemp[x][y] = boardSize[x][y];
    }
}

void GameOfLife::UpdateBoard() {
    for (int j = 0; j < 20; j++) {
        for (int k = 0; k < 20; k++) {
            boardSize[k][j] = boardSizetemp[k][j];
        }
    }
}

void GameOfLife::DisplayBoard() {
    for (int j = 0; j < 20; j++) {
        for (int k = 0; k < 20; k++) {
            std::cout << (boardSize[k][j] ? '*' : '-');
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void GameOfLife::RefreshBoard() {
    for (int j = 0; j < 20; j++) {
        for (int k = 0; k < 20; k++) {
            TestAlive(k, j);
        }
    }
    UpdateBoard();
}
