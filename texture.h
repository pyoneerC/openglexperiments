#pragma once

#include <GL/glew.h>

class texture
{
    private:
        int width;
        int height;
        int nrChannels;

        public:
            unsigned char* data;
            GLuint textur;
            texture(const char* path);
            void Bind();
            void Unbind();
            void Delete();
};