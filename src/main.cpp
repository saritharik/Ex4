#include <iostream>
#include "../include/GameLogic.h"
#include "../include/AI.h"
#include "../include/Game.h"
#include "../include/UserPrinterConsole.h"

using namespace std;

int main() {
    int const defaultSizeBoard = 8;
    BoardConsole bC(defaultSizeBoard, defaultSizeBoard);
    GameLogic gameLogic(&bC);
    Human p1('X');
    UserPrinterConsole printer;
    printer.chooseRival();
    int choice;
    cin >> choice;
    if (choice == 1) {
        Human p2('O');
        Game game(&p1, &p2, &bC, &gameLogic, &printer);
        game.playGame();
    } else if (choice == 2) {
        AI p2(&gameLogic, &bC);
        Game game(&p1, &p2, &bC, &gameLogic, &printer);
        game.playGame();
    }

    return 0;
}