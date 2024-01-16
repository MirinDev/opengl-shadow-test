#version 100

attribute vec3 VERTEX;
attribute vec3 COLOR;

uniform mat4 cam;
uniform mat4 model;

varying vec3 color;

void main()
{
   vec4 vert = model * vec4(VERTEX, 1.0);
   gl_Position = cam * vert;

   color = COLOR;
}