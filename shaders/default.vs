#version 100

attribute vec3 VERTEX;

void main()
{
   gl_Position = vec4(VERTEX, 1.0);
}