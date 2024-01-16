#include <iostream>
using namespace std;

#include <GL/glew.h>
#include <GL/glut.h>

#include <Shader.h>

Shader* shader;
ShaderPart* vsShader;
ShaderPart* fsShader;

void init()
{
    glClearColor(0.1, 0.1, 0.1, 1.0);

    vsShader = new ShaderPart("../shaders/default.vs", GL_VERTEX_SHADER);
    fsShader = new ShaderPart("../shaders/default.fs", GL_FRAGMENT_SHADER);

    shader = new Shader(vector<ShaderPart*>{vsShader, fsShader});

    delete vsShader;
    delete fsShader;
}

void exit()
{
    delete shader;
}

void render()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glutSwapBuffers();
}

int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);

    glutInitWindowSize(640, 480);
    glutCreateWindow("Shadow Sample");

    glewInit();

	glutDisplayFunc(render);

    init();
	glutMainLoop();
    exit();

    return EXIT_SUCCESS;
}
