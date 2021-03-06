//
// Created by tamar on 11/12/17.
//

#ifndef EX4_SERVERPRINTER_H
#define EX4_SERVERPRINTER_H


class ServerPrinter {
public:
    /**
     * wait to client to connect
     */
    void waitToConnection();

    /**
     * after connect to one client, wait to the other
     */
    void waitToOtherClient();

    /**
     * connect to client
     */
    void connect();

    /**
     * the client os disconnect
     */
    void disconnect();

    /**
     * there is erroe on read the x or y coordinate
     * @param cord
     */
    void errorRead(char cord);

    /**
     * error in writing to the client
     */
    void errorWrite();

};


#endif //EX4_SERVERPRINTER_H
