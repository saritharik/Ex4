//
// Created by tamar on 07/12/17.
//

#ifndef EX4_VIRTUALREMOTE_H
#define EX4_VIRTUALREMOTE_H

#include "Player.h"
#include "Client.h"

class VirtualRemote: public Player {
public:
    /**
     * constructor
     * @param client - pointer to client, for connect to the server
     * @param disk - the disk of this player
     */
    VirtualRemote(Client* client, char disk);
    /**
     * Choose square.
     * @return the location of the square.
     */
    virtual Point chooseSquare(vector<Point> vecPoints);
    /**
     * Return the disk.
     * @return the disk.
     */
    virtual char getDisk();
    /**
     * Set points to player.
     * @param newPoints thr points to set.
     */
    virtual void setPoint(int points);
    /**
     * Returns the points.
     * @return the points.
     */
    virtual int getPoint();
private:
    Client* client;
    char disk;
    int points;
};
#endif //EX4_VIRTUALREMOTE_H
