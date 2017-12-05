#ifndef EX4_USERPRINTERCONSOLE_H
#define EX4_USERPRINTERCONSOLE_H

#include "UserInterface.h"

class UserPrinterConsole: public UserInterface {
public:
    UserPrinterConsole();
    virtual void chooseRival();
    virtual void startMove();
    virtual void currentPlayerMsg(char disk);
    virtual void optionsToMove(vector<Point> points);
    virtual void uncorrectMoves(vector<Point> points);
    virtual void endOfGame(char disk);
};
#endif //EX4_USERPRINTERCONSOLE_H
