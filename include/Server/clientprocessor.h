#pragma once

#include "Network/winsocket.h"

class ClientProcessr
{
public:
    ClientProcessr(WinSocket socket) : clientSocket(socket) {};

    void operator() ();

private:
    WinSocket clientSocket;
};