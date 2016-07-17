#include<iostream>
#include <fstream>
#include<conio.h>


#include "ray.h"


//decl
std::ofstream outputfile("RayTracing.ppm");

int ResX=200, ResY=100;
float *R, *G,*B;
struct ColorComp
{

	float R[200][100];
	float G[200][100];
	float B[200][100];

}_ColorComp;


//functions
void WriteToFile();
float Remap(float value, float from1, float to1, float from2, float to2);



glm::vec3 color(const ray &r)
{
	glm::vec3 unit_direction = glm::normalize( r.direction());

	float t = 0.5f*(unit_direction.y + 1.0f);

	return (1.0f - t)*glm::vec3(1.0f, 1.0f, 1.0f) + t*glm::vec3(0.5f,0.7f,0.1f);


};


int main(int argc, char** argv)
{

	//initlise the color array
	for (int i = 0; i < ResX;i++)
	{
		for (int j = 0; j < ResY;j++)
		{
			_ColorComp.R[i][j] =255;
			_ColorComp.B[i][j] =255;
			_ColorComp.G[i][j] = 255;
		
		}	
    }
	
	/*All logic*/
	glm::vec3 lower_left_corner(-2.0f,-1.0f,-1.0f);
	glm::vec3 horizontal(4.0f, -0.0f, 0.0f);
	glm::vec3 vertical(0.0f, 2.0f, 0.0f);
	glm::vec3 origin(0.0f, 0.0f, 0.0f);


	/**/






	WriteToFile();
	getch();
	return 1;
}

void WriteToFile()
{

	outputfile << "P3\n" << ResX << " " << ResY << "\n255\n";
	for (int i = 0; i <ResX; i++)
	{
		for (int j = 0; j < ResY; j++)
		{
			
		
			outputfile << _ColorComp.R[i][j] << " " << _ColorComp.G[i][j] << " " << _ColorComp.B[i][j] << "\n";
			


		}

	}

	

}
/*Util */

float Remap(float value, float from1, float to1, float from2, float to2)
{
	return (value - from1) / (to1 - from1) * (to2 - from2) + from2;
}