#pragma once

#include<iostream>
#include<SDL\SDL.h>
#include <GL\glew.h>
#include <string>
#include "Sprite.h"
#include "GLSLprogram.h"


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
	void initShaders();
	

	void processInput();
	void gameLoop();
	void draw();

	int screenWidth;
	int screenHeight;
	GameState _gameState;

	Sprite _sprite;
	GLSLprogram _colorProgram;
};

