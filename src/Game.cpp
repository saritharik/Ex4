#include <iostream>
#include "../include/Game.h"
Game::Game(Player *p1, Player *p2, Board *b, GameLogic* game,
           UserInterface* userInter):
        p1(p1), p2(p2), b(b), game(game), userInter(userInter) {}

void Game::playGame() {
    int count = 0;
    int const startPoint = 2;
    p1->setPoint(startPoint);
    p2->setPoint(startPoint);
    int sum = ((this->b->getDimensions() - 1) * (this->b->getDimensions() - 1));
    Player* currentPlayer = p1;
    vector<Point>::iterator iter;
    while(p1->getPoint() + p2->getPoint() < sum) {
        userInter->startMove();
        this->b->printBoard();
        if (count == 0) {
            currentPlayer = p1;
        } else {
            currentPlayer = p2;
        }
        userInter->currentPlayerMsg(currentPlayer->getDisk());
        vector<Point> po = game->findPoints(currentPlayer->getDisk());
        userInter->optionsToMove(po);
        if (po.empty()) {
            vector<Point> v1 = game->findPoints(this->p1->getDisk());
            vector<Point> v2 = game->findPoints(this->p2->getDisk());
            if (count == 0) {
                count = 1;
            } else {
                count = 0;
            }
            if (v1.empty() && v2.empty()) {
                break;
            }
            continue;
        }
        Point p = currentPlayer->chooseSquare();
        while ((!game->possibleMoves(p, currentPlayer->getDisk()))
               || (p.getY() == 0 && p.getX() == 0)) {
            userInter->uncorrectMoves(po);
            p = currentPlayer->chooseSquare();
        }
        vector<Point> n1 = game->checking(p.getX(), p.getY(), currentPlayer->getDisk());
        vector<Point> n2 = game->checking(p.getX(), p.getY(), currentPlayer->getDisk());
        game->oneMove(p.getX(), p.getY(), currentPlayer->getDisk());
        if (count == 0) {
            p1->setPoint(1 + n1.size());
            game->setPlayerPoints(p1->getDisk(), p1->getPoint());
            p2->setPoint(-n1.size());
            game->setPlayerPoints(p2->getDisk(), p2->getPoint());
        } else {
            p2->setPoint(1 + n2.size());
            game->setPlayerPoints(p2->getDisk(), p2->getPoint());
            p1->setPoint(-n2.size());
            game->setPlayerPoints(p1->getDisk(), p1->getPoint());
        }
        cout << endl;
        if (count == 0) {
            count = 1;
        } else {
            count = 0;
        }
    }
    this->b->printBoard();
    if (p1->getPoint() > p2->getPoint()) {
        userInter->endOfGame(p1->getDisk());
    } else if (p2->getPoint() > p1->getPoint()) {
        userInter->endOfGame(p2->getDisk());
    } else {
        userInter->endOfGame(' ');
    }
}