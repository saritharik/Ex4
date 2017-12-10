#include "Server.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>
#include <iostream>
using namespace std;
#define MAX_CONNECTED_CLIENTS 2

Server::Server(int port): port(port), serverSocket(0) {
    cout << "Server" << endl;
}
void Server::start() {
    // Create a socket point
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == -1) {
        throw "Error opening socket";
    }

    // Assign a local address to the socket
    struct sockaddr_in serverAddress;
    bzero((void *)&serverAddress, sizeof(serverAddress));
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = INADDR_ANY; //IP
    serverAddress.sin_port = htons(port);
    if (bind(serverSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) == -1) {
        throw "Error on binding";
    }
    // Start listening to incoming connections
    listen(serverSocket, MAX_CONNECTED_CLIENTS);
    // Define the client socket's structures
    struct sockaddr_in clientAddressX;
    struct sockaddr_in clientAddressO;
    socklen_t clientAddressLenX;
    socklen_t clientAddressLenO;

    while (true) {
        cout << "Waiting for client connections..." << endl;
        // Accept a new client connection
        int clientSocketX = accept(serverSocket, (struct
                sockaddr *)&clientAddressX, &clientAddressLenX);
        if (clientSocketX == -1)
            throw "Error on accept";
        cout << "First client connected, wait to another client" << endl;
        int X = 1;
        int O = 2;
        write(clientSocketX, &X, sizeof(X));
        int clientSocketO = accept(serverSocket, (struct
                sockaddr *)&clientAddressO, &clientAddressLenO);
        if (clientSocketO == -1)
            throw "Error on accept";
        cout << "Client connected" << endl;
        write(clientSocketO, &O, sizeof(O));

        handleClient(clientSocketX, clientSocketO);
        // Close communication with the client
        close(clientSocketX);
        close(clientSocketO);
    }
}

// Handle requests from a specific client
void Server::handleClient(int clientSocketX, int clientSocketO) {
    int X = 1, O = 2;
    int xPoint1, yPoint1, xPoint2, yPoint2;

    //init the game
    write(clientSocketX, &X, sizeof(X));
    write(clientSocketO, &O, sizeof(O));

    while (true) {
        int n = read(clientSocketX, &xPoint1, sizeof(xPoint1));
        if (n == -1) {
            cout << "Error reading x Point" << endl;
            return;
        }
        if (n == 0) {
            cout << "Client disconnected" << endl;
            //close(clientSocketO);
            //close(clientSocketX);
            return;
        }

        n = read(clientSocketX, &yPoint1, sizeof(yPoint1));
        if (n == -1) {
            cout << "Error reading y Point" << endl;
            return;
        }
        Point moveX(xPoint1, yPoint1);
        if (xPoint1 == -1 && yPoint1 == -1) {
            //close(clientSocketX);
            return;
        }

        // Write the result back to the O client
        n = write(clientSocketO, &moveX, sizeof(moveX));
        if (n == -1) {
            cout << "Error writing to socket" << endl;
            return;
        }

        //move to the O player
        n = read(clientSocketO, &xPoint2, sizeof(xPoint2));
        if (n == -1) {
            cout << "Error reading x Point" << endl;
            return;
        }
        if (n == 0) {
            cout << "Client disconnected" << endl;
            //close(clientSocketX);
            //close(clientSocketO);
            return;
        }

        n = read(clientSocketO, &yPoint2, sizeof(yPoint2));
        if (n == -1) {
            cout << "Error reading y Point" << endl;
            return;
        }
        Point moveO(xPoint2, yPoint2);
        if (xPoint2 == -1 && yPoint2 == -1) {
            //close(clientSocketO);
            return;
        }

        // Write the result back to the X client
        n = write(clientSocketX, &moveO, sizeof(moveO));
        if (n == -1) {
            cout << "Error writing to socket" << endl;
            return;
        }
    }
}

void Server::stop() {
    close(serverSocket);
}