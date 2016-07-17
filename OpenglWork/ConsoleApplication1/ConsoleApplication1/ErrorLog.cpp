#include "ErrorLog.h"

#include<cstdlib>

void fatalError(std::string errorName)
{
	std::cout << errorName<<"\n";
	std::cout << "Press key to quit..";
	int temp;
	std::cin >> temp;
	SDL_Quit();
	exit(1);
};
