// Chat.cpp: определяет точку входа для приложения.
//
#include <iostream>

#include "Network/ipaddr.h"
#include "Server/server.h"

using namespace std;

int main(int argc, char* argv[])
{
	IpAddr ip1 = IpAddr("0.0.0.0");
	IpAddr ip2 = IpAddr("127.0.0.1");
	IpAddr ip3 = IpAddr("255.255.255.255");

	std::cout << "addr" << std::endl;
	std::cout << ip2 << std::endl;

	try
	{
		IpAddr ip4 = IpAddr(" ");
	}
	catch (const std::exception& ex)
	{
		std::cout << ex.what() << std::endl;
	}

	try
	{
		IpAddr ip5 = IpAddr(".1.");
	}
	catch (const std::exception& ex)
	{
		std::cout << ex.what() << std::endl;
	}

	for (int i = 1; i < argc; i++)
	{
		if (argv[i] == "-c")
		{
			std::cout << "run client side";
		}
		else
		{
			std::cout << "run server side";
			auto server = Server();
			server.start();
		}
	}

	return 0;
}
