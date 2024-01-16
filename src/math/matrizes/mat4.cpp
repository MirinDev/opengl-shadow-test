#include <math/matrizes/mat4.h>

mat4::mat4(float v)
{
    data[0] = v;
    data[5] = v;
    data[10] = v;
    data[15] = v;
}

mat4 mat4::operator*(const mat4& m)
{
    mat4 r = mat4();

    for (int i = 0; i < 4; i += 2)
    {
        __m256 v1_id = _mm256_loadu_ps(&data[i * 4]);

        for (int j = 0; j < 4; j++)
        {
            __m256 v2_id = _mm256_set_ps(m.data[12 + j], m.data[8 + j], m.data[4 + j], m.data[j], 
                                         m.data[12 + j], m.data[8 + j], m.data[4 + j], m.data[j]);
            
            __m256 v = _mm256_mul_ps(v1_id, v2_id);
            r.data[4 * i + 4 + j] = v[7] + v[6] + v[5] + v[4];
            r.data[4 * i + j]       = v[3] + v[2] + v[1] + v[0];
        }
    }

    return r;
}

float mat4::operator[](unsigned int i)
{
    return data[i];
}

mat4 mat4::translate(float x, float y, float z)
{
    mat4 m = mat4(1.0);

    m.data[3] = x;
    m.data[7] = y;
    m.data[11] = z;
    
    return *this * m;
}

mat4 mat4::rotate_y(float r)
{
    mat4 m = mat4(1.0f);

    m.data[0] = cos(r);
    m.data[2] = sin(r);
    m.data[8] = -sin(r);
    m.data[10] = cos(r);

    return *this * m;
}

mat4 project(float aspect, float fov, float near, float far)
{
    mat4 r = mat4();

    float ar = tanf(fov / 2.0f);

    r.data[0] = 1 / (aspect * ar);
    r.data[5] = 1 / ar;
    r.data[10] = - (far + near) / (far - near);
    r.data[11] = - (2 * far * near) / (far - near);

    r.data[14] = -1;

    return r;
}
