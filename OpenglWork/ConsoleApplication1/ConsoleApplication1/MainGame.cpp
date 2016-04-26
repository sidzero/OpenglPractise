#include "MainGame.h"


MainGame::MainGame()
{
	_window = nullptr;
	screenWidth = 1024;
	screenHeight = 768;
}


MainGame::~MainGame()
{
}

void MainGame::run()
{
	initSystems();
};

void MainGame::initSystems()
{
	//getting SDL initliase
	SDL_Init(SDL_INIT_EVERYTHING);
	
	_window = SDL_CreateWindow(" MY GAME ENGINE", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,screenWidth,screenHeight,SDL_WINDOW_OPENGL);
};
