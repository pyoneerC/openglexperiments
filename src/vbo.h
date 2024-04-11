#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

class vbo
{
	public:
		GLuint VBO;
		vbo(GLfloat* vertices, GLsizeiptr size);

		void Bind();
		void Unbind();
		void Delete();

private:
	unsigned int m_RendererID;
};

