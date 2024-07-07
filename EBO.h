#ifndef EBO_H
#define EBO_H

#include<glad/glad.h>

class EBO {

public:
	GLuint ID;
	EBO(GLuint* inices, GLsizeiptr size);

	void Bind();
	void Unbind();
	void Delete();
};

#endif