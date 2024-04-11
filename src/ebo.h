#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

class ebo
{
	public:
		GLuint EBO;
		ebo(GLuint* indices, GLsizeiptr size);

		void Bind();
		void Unbind();
		void Delete();
};