#pragma once

#include<iostream>
#include<SDL\SDL.h>
#include <GL\glew.h>


enum class GameState{ PLAY,EXIT};

class MainGame
{
public:
	MainGame();
	~MainGame();

	void run();

	

private:
	SDL_Window* _window;
	void initSystems();

	void processInput();
	void gameLoop();

	int screenWidth;
	int screenHeight;
	GameState _gameState;

};

