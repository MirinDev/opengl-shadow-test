#pragma once

#include <cmath>
#include <immintrin.h>
#include "../vectors.h"

class mat4
{
    public:
        mat4(){};
        mat4(float v);

        mat4 translate(float x, float y, float z);
        mat4 rotate_y(float r);

        mat4 operator*(const mat4& m);
        float operator[](unsigned int i);

        float data[16] = {0.0f};
};

mat4 project(float aspect, float fov, float near, float far);
