//
// Created by tamar on 07/12/17.
//

#include "../include/Remote.h"
#include <iostream>
#include <limits>

using namespace std;

Remote::Remote(): client("127.0.0.1", 8000) {
    this->disk = client.connectToServer();
}

Point Remote::chooseSquare(vector<Point> vecPoints) {
    bool b = false;
    int x, y;
    while (b == false) {
        char a;
        cin >> x >> a >> y;
        while (!x || !y) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> x >> a >> y;
        }
        vector<Point>::iterator iter;
        for (iter = vecPoints.begin(); iter != vecPoints.end(); iter++) {
            if ((iter.base()->getX() == x) &&
                iter.base()->getY() == y) {
                b = true;
                break;
            }
        }
    }
    client.sendMessage(Point(x, y));
    return Point(x, y);
}

char Remote::getDisk() {
    return this->disk;
}

int Remote::getPoint() {
    return points;
}
void Remote::setPoint(int newPoints) {
    this->points += newPoints;
}