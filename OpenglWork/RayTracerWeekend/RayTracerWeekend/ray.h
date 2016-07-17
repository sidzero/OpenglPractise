#pragma once
#include<glm.hpp>
#include <vec3.hpp> // glm::vec3
#include <vec4.hpp> // glm::vec4
#include <mat4x4.hpp> // glm::mat4
#include <gtc/matrix_transform.hpp> 
class ray
{
public:
	ray();
	ray(const glm::vec3 &a, const glm::vec3 &b){ A = a; B = b; };
	glm::vec3 orgin() const{ return A; }
	glm::vec3 direction() const{ return B; }
	glm::vec3 point_at_parameter(float t) const{ return A+ t*B; }
	~ray();

	glm::vec3 A,B;//start point and end point
};

