#include "ebo.h"

#include <GLFW/glfw3.h>
#include <GL/glew.h>

ebo::ebo(GLuint* indices, GLsizeiptr size)
{
	glGenBuffers(1, &EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, indices, GL_STATIC_DRAW);
}

void ebo::Bind()
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
}

void ebo::Unbind()
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void ebo::Delete()
{
	glDeleteBuffers(1, &EBO);
}