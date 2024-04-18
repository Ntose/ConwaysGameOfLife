#pragma once

class GameOfLife {
public:
    bool boardSize[20][20] = { false };
    bool boardSizetemp[20][20] = { false };
    int alivecnt = 0;
public:
    void SetBoard();
    void TestAlive(int x, int y);
    void DisplayBoard();
    void RefreshBoard();
    void UpdateBoard();
};
