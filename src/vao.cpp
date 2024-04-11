#include "vao.h"

vao::vao() {
	glGenVertexArrays(1, &id);
}

void vao::LinkVBO(vbo& VBO, GLuint layout) {
	VBO.Bind();
	glVertexAttribPointer(layout, 3, GL_FLOAT, GL_FALSE, 0, NULL);
	glEnableVertexAttribArray(layout);
	VBO.Unbind();
}

void vao::Bind() {
	glBindVertexArray(id);
}

void vao::Unbind() {
	glBindVertexArray(0);
}

void vao::Delete() {
	glDeleteVertexArrays(1, &id);
}

