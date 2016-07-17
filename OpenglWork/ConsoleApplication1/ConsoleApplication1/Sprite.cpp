#include "Sprite.h"


Sprite::Sprite()
{
}


Sprite::~Sprite()
{
	if (_VboID != 0 )
	{
		glDeleteBuffers(1,&_VboID);
	}
}

void Sprite::init(GLfloat x, GLfloat y, GLfloat width, GLfloat height)
{
	_X = x;
	_Y = y;
	_Width = width;
	_Height = height;



	if (_VboID == 0)
	{
		glGenBuffers(1, &_VboID);
	}

	float vertexData[12];

	//1st triangle (anti clockwise)
	vertexData[0] = _X + _Width;
	vertexData[1] = _Y + _Height;

	vertexData[2] = _X;
	vertexData[3] = _Y + _Height;

	vertexData[4] = _X;
	vertexData[5] = _Y;

	//2nd triangle
	vertexData[6] = _X;
	vertexData[7] = _Y;

	vertexData[8] = _X + _Width;
	vertexData[9] = _Y;

	vertexData[10] = _X + _Width;
	vertexData[11] = _Y + _Height;
	//--------------------------------

	glBindBuffer(GL_ARRAY_BUFFER,_VboID);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertexData), vertexData, GL_STATIC_DRAW);

	glBindBuffer(GL_ARRAY_BUFFER,0);//unbind buffer




};

void Sprite::Draw()
{

	glBindBuffer(GL_ARRAY_BUFFER, _VboID);


	glEnableVertexAttribArray(0);

	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, 0);

	glDrawArrays(GL_TRIANGLES, 0 , 6);


	glDisableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);//unbind buffer
};