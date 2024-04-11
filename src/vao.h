#include "vbo.h"

class vao {
public:
		  GLuint id;
		  vao();

		  void LinkVBO(vbo& VBO, GLuint layout);
		  void Bind();
		  void Unbind();
		  void Delete();
};