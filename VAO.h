#ifndef VAO_H
#define VAO_H

#include"VBO.h"
#include<glad/glad.h>

class VAO {

public:
	GLuint ID;
	VAO();

	void LinkVBO(VBO VBO, GLuint layout);
	void Bind();
	void Unbind();
	void Delete();
};

#endif

