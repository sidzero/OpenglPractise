#pragma once
#include <windows.h>
#include <gl\glew.h>
#include <gl\GL.h>
#include <string>
#include<iostream>
#include<SDL\SDL.h>
#include <GL\glew.h>
#include <string>
#include "ErrorLog.h"
class GLSLprogram
{
  public:
	GLSLprogram();
	~GLSLprogram();
	void Compile(const std::string &vertexPath, const std::string &fragPath);
	void Link();
	void addAttribute(const std::string &atributeName );

	void Use();
	void UnUse();

  private:
	  GLuint program,vertexProgram,fragProgram;
	  GLint attributeNumber;
	  void compileshader(const std::string &vertexPath,GLuint ID);
	
	 
	 

};

