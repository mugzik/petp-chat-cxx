#pragma once

#include <string>

#include "Network/winsocket.h"

class Client
{
public:


private:
    int serverPort = 5000;
    std::string serverAddress = "127.0.0.1";

    WinSocket socket;
};