#include "game_of_life.h"
#include <iostream>

int main() {
    srand(time(NULL));
    bool c = true;
    GameOfLife game;
    game.SetBoard();
    while (c == true) {
        game.DisplayBoard();
        game.RefreshBoard();

        std::cout << "Continue [yes/no, 1/0]: ";
        std::cin >> c;
    }

    return 0;
}
