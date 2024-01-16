#pragma once

#include <iostream>
#include <stdexcept>
#include <fstream>
#include <sstream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

#include <GL/glew.h>

class ShaderPart
{
    public:
        ShaderPart(string file_path, GLuint type);
        ~ShaderPart();

        GLuint id;
};