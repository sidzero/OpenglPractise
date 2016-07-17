#include "GLSLprogram.h"
#include <fstream>
#include <vector>

GLSLprogram::GLSLprogram() :program(0), vertexProgram(0), fragProgram(0), attributeNumber(0)
{

}


GLSLprogram::~GLSLprogram()
{

}

void GLSLprogram::Compile(const std::string &vertexPath, const std::string &fragPath)
{
	program = glCreateProgram();
	vertexProgram = glCreateShader(GL_VERTEX_SHADER);
	if (vertexProgram == 0)
	{
		fatalError("vertex program cannot be created");
	
	}

	fragProgram = glCreateShader(GL_FRAGMENT_SHADER);
	if (fragProgram == 0)
	{
		fatalError("fragment program cannot be created");
	}

	compileshader(vertexPath , vertexProgram);
	compileshader(fragPath, fragProgram);
	



};

void GLSLprogram::compileshader(const std::string &vertexPath , GLuint ID)
{

	//VERTEX PROGRAM COMPILING
	std::ifstream vertexFile(vertexPath);
	if (vertexFile.fail())
	{
		perror(vertexPath.c_str());
		fatalError("Failed to open the file " + vertexPath);
	}

	std::string fileContent = "";
	std::string line;

	while (std::getline(vertexFile, line))
	{
		fileContent += line + "\n";
	}
	vertexFile.close();

	const char* contentPtr = fileContent.c_str();
	glShaderSource(ID, 1, &contentPtr, nullptr);

	glCompileShader(ID);

	GLint sucess = 0;
	glGetShaderiv(ID, GL_COMPILE_STATUS, &sucess);

	if (sucess == GL_FALSE)
	{
		GLint maxLength = 0;
		glGetShaderiv(ID, GL_INFO_LOG_LENGTH, &maxLength);

		// The maxLength includes the NULL character
		std::vector<GLchar> errorLog(maxLength);
		glGetShaderInfoLog(ID, maxLength, &maxLength, &errorLog[0]);

		// Provide the infolog in whatever manor you deem best.
		// Exit with failure.
		glDeleteShader(ID); // Don't leak the shader.

		std::printf("%s \n", &(errorLog[0]));
		fatalError("  Shader Failed to compile "+vertexPath);
		return;
	}
};

void GLSLprogram::Link()
{
	

	//Attach shaders as necessary.
	glAttachShader(program, vertexProgram);
	glAttachShader(program, fragProgram);

		//Link the program.
		glLinkProgram(program);

	GLint isLinked = 0;
	glGetProgramiv(program, GL_LINK_STATUS, &isLinked);
	if (isLinked == GL_FALSE)
	{
		GLint maxLength = 0;
		glGetProgramiv(program, GL_INFO_LOG_LENGTH, &maxLength);

		//The maxLength includes the NULL character
		std::vector<GLchar> infoLog(maxLength);
		glGetProgramInfoLog(program, maxLength, &maxLength, &infoLog[0]);

		std::printf("%s \n", &(infoLog[0]));
		fatalError("  Shader Failed to Link ");

		//The program is useless now. So delete it.
		glDeleteProgram(program);
		glDeleteShader(vertexProgram);
		glDeleteShader(fragProgram);
		//Provide the infolog in whatever manner you deem best.
		//Exit with failure.
		return;
	}

	glDetachShader(program,vertexProgram);
	glDetachShader(program,fragProgram);
	glDeleteShader(vertexProgram);
	glDeleteShader(fragProgram);



};

void GLSLprogram::addAttribute(const std::string &atributeName)
{

	glBindAttribLocation( program , attributeNumber++ ,atributeName.c_str());
};

void GLSLprogram::Use()
{
	glUseProgram(program);
	for (int i = 0; i < attributeNumber;i++)
	{
		glEnableVertexAttribArray(i);
	}

};
void GLSLprogram::UnUse()
{
	glUseProgram(0);
	for (int i = 0; i < attributeNumber; i++)
	{
		glDisableVertexAttribArray(i);
	}
}