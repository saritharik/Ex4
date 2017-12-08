#include <iostream>
#include "../include/GameLogic.h"
#include "../include/AI.h"
#include "../include/Game.h"
#include "../include/UserPrinterConsole.h"
#include "../include/Client.h"
#include "../include/Remote.h"
#include "../include/VirtualRemote.h"

using namespace std;

int main() {
    int const defaultSizeBoard = 4;
    BoardConsole bC(defaultSizeBoard, defaultSizeBoard);
    GameLogic gameLogic(&bC);
    Human p1('X');
    UserPrinterConsole printer;
    printer.chooseRival();
    int choice;
    cin >> choice;
    if (choice == 1) {
        Human p2('O');
        Game game(&p1, &p2, &bC, &gameLogic, &printer, false);
        game.playGame();
    } else if (choice == 2) {
        AI p2(&gameLogic, &bC);
        Game game(&p1, &p2, &bC, &gameLogic, &printer, false);
        game.playGame();
    } else if (choice == 3) {
        Client client("127.0.0.1", 8000);
        char disk = client.connectToServer();
        Remote player1(&client, disk);
        char rivalDisk = ' ';
        if (disk == 'X') {
            rivalDisk = 'O';
            VirtualRemote player2(&client, rivalDisk);
            Game game(&player1, &player2, &bC, &gameLogic, &printer, true);
            game.playGame();
        } else if (disk == 'O') {
            rivalDisk = 'X';
            VirtualRemote player2(&client, rivalDisk);
            Game game(&player2, &player1, &bC, &gameLogic, &printer, true);
            game.playGame();
        }

    }

    return 0;
}