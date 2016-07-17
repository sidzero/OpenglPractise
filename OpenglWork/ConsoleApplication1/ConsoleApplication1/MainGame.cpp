#include "MainGame.h"
#include "ErrorLog.h"

//void fatalError(std::string errorName)
//{
//	std::cout << errorName<<"\n";
//	std::cout << "Press key to quit..";
//	int temp;
//	std::cin >> temp;
//	SDL_Quit();
//};

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

	_sprite.init(-1.0f,-1.0f,0.1f,2.0f);

	//run game loop
	gameLoop();


};

void MainGame::initSystems()
{
	//getting SDL initliase
	SDL_Init(SDL_INIT_EVERYTHING);
	
	_window = SDL_CreateWindow(" MY GAME ENGINE", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,screenWidth,screenHeight,SDL_WINDOW_OPENGL);
	if (_window == nullptr)
	{
		fatalError("Window not created");

	}
	//opengl context creations
	SDL_GLContext glContext = SDL_GL_CreateContext(_window);

	if (glContext == nullptr)
	{
		fatalError("Opengl context couldn't be created");
	}

	glewExperimental = true;
	GLenum error = glewInit();
	if (error != GLEW_OK)
	{
		fatalError("glew not intilasied");
	}

	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER,1);

	//background colour
	glClearColor(0,1.0f,0,1.0f);
	initShaders();

};

void MainGame::initShaders()
{
	_colorProgram.Compile("E:/WORKINPROGRESS/OpenglBeginiinng/OpenglWork/ConsoleApplication1/Shaders/colorVertex.txt", "E:/WORKINPROGRESS/OpenglBeginiinng/OpenglWork/ConsoleApplication1/Shaders/colorFrag.txt");
	_colorProgram.addAttribute("vertexPosition");
	_colorProgram.Link();
}

void MainGame::gameLoop()
{
	while (_gameState!=GameState::EXIT)
	{
		processInput();

		draw();
	}
};

void MainGame::draw()
{
	glClearDepth(1.0);
	glClear(GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT );

	_colorProgram.Use();
	_sprite.Draw();
	_colorProgram.UnUse();

	SDL_GL_SwapWindow(_window);
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
