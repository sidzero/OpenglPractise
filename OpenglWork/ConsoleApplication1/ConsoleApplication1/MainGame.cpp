#include "MainGame.h"


MainGame::MainGame()
{
	_window = nullptr;
	screenWidth = 1024;
	screenHeight = 768;
	_gameState = GameState::PLAY;
}


MainGame::~MainGame()
{
}

void MainGame::run()
{
	initSystems();

	//run game loop
	gameLoop();


};

void MainGame::initSystems()
{
	//getting SDL initliase
	SDL_Init(SDL_INIT_EVERYTHING);
	
	_window = SDL_CreateWindow(" MY GAME ENGINE", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,screenWidth,screenHeight,SDL_WINDOW_OPENGL);
};


void MainGame::gameLoop()
{
	while (_gameState!=GameState::EXIT)
	{
		processInput();
	}
};

void MainGame::processInput()
{
	SDL_Event evnt;

	while ( SDL_PollEvent(&evnt) )
	{
		switch (evnt.type)
		{
		case SDL_QUIT:
			_gameState = GameState::EXIT;
			break;
		case SDL_MOUSEMOTION:
			std::cout << evnt.motion.x << " " << evnt.motion.y<<"\n";
			break;



		}
	}

};
