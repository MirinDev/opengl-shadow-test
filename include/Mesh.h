#pragma once

#include <iostream>
#include <vector>
using namespace std;

#include <GL/glew.h>

class Mesh
{
    public:
        Mesh(vector<float> vertices, vector<unsigned int> indices);
        ~Mesh();

        void render();

        GLuint id;
    
    private:
        unsigned int size;
};