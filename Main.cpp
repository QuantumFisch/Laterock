#include<iostream>
#include<fstream>
#include<cerrno>
#include<glad/glad.h>
#include<GLFW/glfw3.h>

#include"Shader.h"
#include"VBO.h"
#include"EBO.h"
#include"VAO.h"

GLfloat vertices[] = {
	0.0, 0.0, 0.0,
	0.5, 0.0, 0.0,
	0.0, 0.5, 0.0
};

GLuint indices[] = {
	0,1,2
};



GLint uniID;

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {

	if (action == GLFW_PRESS) {
		switch (key) {
		case GLFW_KEY_W:
			std::cout << uniID;
			glUniform2f(uniID, -0.1f, -0.1f);
			break;
		case GLFW_KEY_A:
			break;
		}
	}

};



int main() {



	glfwInit();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_COMPAT_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(400, 400, "OpenGl", NULL, NULL);

	glfwSetKeyCallback(window, key_callback);
	
	glfwMakeContextCurrent(window);

	gladLoadGL();

	glViewport(0,0,400,400);

	Shader shaderProgram("vs.vert" ,"fs.frag");

	VAO VAO1;
	VAO1.Bind();

	VBO VBO1(vertices, sizeof(vertices));
	EBO EBO1(indices, sizeof(indices));

	VAO1.LinkVBO(VBO1, 0);
	VAO1.Unbind();
	VBO1.Unbind();
	EBO1.Unbind();


		uniID = glGetUniformLocation(shaderProgram.ID, "offset");

	while (!glfwWindowShouldClose(window)) {

		glClearColor(0.4f, 0.3f, 0.7f, 0.0f);
		glClear(GL_COLOR_BUFFER_BIT);


		shaderProgram.Activate();
		glUniform2f(uniID, -0.1f, -0.1f);
		VAO1.Bind();


		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, 0);

		glfwSwapBuffers(window);
		
	
		glfwPollEvents();
	}

	VAO1.Delete();
	VBO1.Delete();
	EBO1.Delete();
	shaderProgram.Delete();


	glfwDestroyWindow(window);
	glfwTerminate();
}
