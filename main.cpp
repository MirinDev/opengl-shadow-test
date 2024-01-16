#include <iostream>
using namespace std;

#include <GL/glew.h>
#include <GL/glut.h>

#include <Shader.h>
#include <Mesh.h>

Shader* shader;
ShaderPart* vsShader;
ShaderPart* fsShader;

Mesh* mesh;

vector<float> vertices = 
{
    -0.5, -0.5, 0.0, 
     0.5, -0.5, 0.0, 
     0.0,  0.5, 0.0
};

vector<unsigned int> indices = 
{
    0, 1, 2
};

void init()
{
    glClearColor(0.1, 0.1, 0.1, 1.0);

    vsShader = new ShaderPart("../shaders/default.vs", GL_VERTEX_SHADER);
    fsShader = new ShaderPart("../shaders/default.fs", GL_FRAGMENT_SHADER);

    shader = new Shader(vector<ShaderPart*>{vsShader, fsShader});

    delete vsShader;
    delete fsShader;

    shader->use();

    mesh = new Mesh(vertices, indices);
}

void exit()
{
    delete shader;
}

void render()
{
    glClear(GL_COLOR_BUFFER_BIT);

    mesh->render();

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
