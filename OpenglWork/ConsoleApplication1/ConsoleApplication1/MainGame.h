#pragma once

#include<SDL\SDL.h>
#include <GL\glew.h>

class MainGame
{
public:
	MainGame();
	~MainGame();

	void run();

	void initSystems();

private:
	SDL_Window* _window;
	int screenWidth;
	int screenHeight;

};

