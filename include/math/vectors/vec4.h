#pragma once

#include <cmath>
#include <immintrin.h>

class vec4
{
    public:
        vec4(float x, float y, float z, float w);

        vec4 operator+(const vec4& v);
        vec4 operator-(const vec4& v);
        vec4 operator*(const vec4& v);
        vec4 operator/(const vec4& v);

        float x, y, z, w;
};
