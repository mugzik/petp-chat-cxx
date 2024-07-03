// Chat.cpp: определяет точку входа для приложения.
//
#include "main.h"

using namespace std;

int main(int argc, char* argv[])
{
	for (int i = 1; i < argc; i++)
	{
		if (argv[i] == "-c")
		{
			std::cout << "run client side";
		}
		else
		{
			std::cout << "run server side";
		}
	}

	return 0;
}
