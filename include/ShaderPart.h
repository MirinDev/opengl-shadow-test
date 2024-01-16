#pragma once

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

#include <GL/glew.h>

class ShaderPart
{
    public:
        ShaderPart(string file_path, GLuint type);
        ~ShaderPart();

        GLuint id;
};