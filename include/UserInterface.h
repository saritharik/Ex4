
#ifndef EX4_USERINTERFACE_H
#define EX4_USERINTERFACE_H

#include "Point.h"
#include <vector>
using namespace std;

class UserInterface {
public:
    virtual void chooseRival() = 0;
    virtual void startMove() = 0;
    virtual void currentPlayerMsg(char disk) = 0;
    virtual void optionsToMove(vector<Point> points) = 0;
    virtual void uncorrectMoves(vector<Point> points) = 0;
    virtual void endOfGame(char disk) = 0;

};
#endif //EX4_USERINTERFACE_H
