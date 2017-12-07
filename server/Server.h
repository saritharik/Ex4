//
// Created by tamar on 07/12/17.
//

#ifndef EX4_SERVER_H
#define EX4_SERVER_H


class Server {
public:
    Server(int port);
    void start();
    void stop();
private:
    int port;
    int serverSocket; // the socket's file descriptor
    void handleClient(int clientSocketX, int clientSocketO);
    //int calc(int arg1, const char op, int arg2) const;
};


#endif //EX4_SERVER_H
