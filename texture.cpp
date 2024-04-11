#include "texture.h"
#include "Dependencies/STB/stb_image.h"
#include <iostream>


texture::texture(const char* path) {
	// Load the texture image
	int width, height, nrChannels;
	stbi_set_flip_vertically_on_load(true);
	unsigned char* data = stbi_load(path, &width, &height, &nrChannels, 0);

	// Generate and bind texture
	glGenTextures(1, &textur);
	glBindTexture(GL_TEXTURE_2D, textur);
	glActiveTexture(GL_TEXTURE0);

	// Set the texture wrapping parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	// Set texture filtering parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	// Load texture data
	if (data) {
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else {
		printf("Failed to load texture\n");
	}
	stbi_image_free(data);
}

void texture::Bind() {
	glBindTexture(GL_TEXTURE_2D, textur);
}

void texture::Unbind() {
	glBindTexture(GL_TEXTURE_2D, 0);
}

void texture::Delete() {
	glDeleteTextures(1, &textur);
}