//
// Created by tamar on 07/12/17.
//

#ifndef EX4_REMOTE_H
#define EX4_REMOTE_H

#include "Player.h"
#include "Client.h"

class Remote: public Player {
public:
    /**
     * constructor
     * @param serverIP the IP of the server
     * @param serverPort the number port of the server
     */
    Remote();
    /**
     * Choose square.
     * @return the location of the square.
     */
    virtual Point chooseSquare(vector<Point> vecPoints) = 0;
    /**
     * Return the disk.
     * @return the disk.
     */
    virtual char getDisk() = 0;
    /**
     * Set points to player.
     * @param newPoints thr points to set.
     */
    virtual void setPoint(int points) = 0;
    /**
     * Returns the points.
     * @return the points.
     */
    virtual int getPoint() = 0;
private:
    Client client;
    char disk;
    int points;
};

#endif //EX4_REMOTE_H
