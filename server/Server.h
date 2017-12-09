#ifndef EX4_SERVER_H
#define EX4_SERVER_H


#include "../include/Point.h"
class Server {
public:
    /**
     * Constructor
     * @param port - number of port.
     */
    Server(int port);
    /**
     * Start the connection.
     */
    void start();
    /**
     * Stop the connection.
     */
    void stop();
private:
    int port;
    int serverSocket; // the socket's file descriptor
    void handleClient(int clientSocketX, int clientSocketO);
};


#endif //EX4_SERVER_H
