//
// Created by tamar on 07/12/17.
//

#ifndef EX4_CLIENT_H
#define EX4_CLIENT_H

#include "Point.h"

class Client {
public:
    Client(const char *serverIP, int serverPort);
    char connectToServer();
    Point getMessage();
    void sendMessage(Point newPoint);
private:
    const char *serverIP;
    int serverPort;
    int clientSocket;
};
#endif //EX4_CLIENT_H
