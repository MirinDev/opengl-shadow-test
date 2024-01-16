#pragma once

#include <iostream>
#include <vector>
using namespace std;

#include <GL/glew.h>
#include "ShaderPart.h"

class Shader
{
    public:
        Shader(vector<ShaderPart*> parts);
        ~Shader();

        void use();
        GLuint id;
};
