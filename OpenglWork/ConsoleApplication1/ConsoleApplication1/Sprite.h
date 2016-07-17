#pragma once
#include <windows.h>
#include <gl\glew.h>
#include <gl\GL.h>

class Sprite
{
public:
	Sprite();
	~Sprite();
	void init(GLfloat x,GLfloat y,GLfloat width,GLfloat height);
	void Draw();

private:
	
	GLfloat _X, _Y, _Width, _Height;
	GLuint _VboID;
};

