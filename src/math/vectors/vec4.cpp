#include <math/vectors/vec4.h>

vec4::vec4(float x, float y, float z, float w)
{
    this->x = x;
    this->y = y;
    this->z = z;
    this->w = w;
}

vec4 vec4::operator+(const vec4& v)
{
    __m128 v1_id = _mm_set_ps(x, y, z, w);
    __m128 v2_id = _mm_set_ps(v.x, v.y, v.z, v.w);

    __m128 v_id = _mm_add_ps(v1_id, v2_id);
    float* array = (float*)&v_id;

    return vec4(array[3], array[2], array[1], array[0]);
}

vec4 vec4::operator-(const vec4& v)
{
    __m128 v1_id = _mm_set_ps(x, y, z, w);
    __m128 v2_id = _mm_set_ps(v.x, v.y, v.z, v.w);

    __m128 v_id = _mm_sub_ps(v1_id, v2_id);
    float* array = (float*)&v_id;

    return vec4(array[3], array[2], array[1], array[0]);
}

vec4 vec4::operator*(const vec4& v)
{
    __m128 v1_id = _mm_set_ps(x, y, z, w);
    __m128 v2_id = _mm_set_ps(v.x, v.y, v.z, v.w);

    __m128 v_id = _mm_mul_ps(v1_id, v2_id);
    float* array = (float*)&v_id;

    return vec4(array[3], array[2], array[1], array[0]);
}

vec4 vec4::operator/(const vec4& v)
{
    __m128 v1_id = _mm_set_ps(x, y, z, w);
    __m128 v2_id = _mm_set_ps(v.x, v.y, v.z, v.w);

    __m128 v_id = _mm_div_ps(v1_id, v2_id);
    float* array = (float*)&v_id;

    return vec4(array[3], array[2], array[1], array[0]);
}