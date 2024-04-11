#include "vbo.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>

vbo::vbo(GLfloat* vertices, GLsizeiptr size)
{
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
}

void vbo::Bind()
{
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
}

void vbo::Unbind()
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void vbo::Delete()
{
	glDeleteBuffers(1, &VBO);
}