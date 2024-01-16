#include <iostream>
using namespace std;

#include <GL/glew.h>
#include <GL/glut.h>

#include <Shader.h>
#include <Mesh.h>

#include <math/vectors.h>
#include <math/matrizes.h>
#include <math/utils.h>

Shader* shader;
ShaderPart* vsShader;
ShaderPart* fsShader;

Mesh* mesh;

vector<float> vertices = 
{
    -0.5, -0.5, 0.0,    1.0, 0.0, 0.0,
     0.5, -0.5, 0.0,    0.0, 1.0, 0.0,
     0.0,  0.5, 0.0,    0.0, 0.0, 1.0
};

vector<unsigned int> indices = 
{
    0, 1, 2
};

mat4 proj;
mat4 view;
mat4 model;

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

    proj = project(640.0 / 380.0, DEGTORAD(90.0), 0.1, 100.0);
    view = mat4(1.0).translate(0.0, 0.0, -2.0);
    model = mat4(1.0);

    glUniformMatrix4fv(glGetUniformLocation(shader->id, "cam"), 1, GL_FALSE, (proj * view).data);
}

void exit()
{
    delete shader;
}

void update()
{
    model = model.rotate_y(DEGTORAD(1));
}

void render()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glUniformMatrix4fv(glGetUniformLocation(shader->id, "model"), 1, GL_FALSE, model.data);
    mesh->render();

    glutSwapBuffers();
    glutPostRedisplay();
}

int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);

    glutInitWindowSize(640, 480);
    glutCreateWindow("Shadow Sample");

    glewInit();

	glutDisplayFunc(render);
    glutIdleFunc(update);

    init();
	glutMainLoop();
    exit();

    return EXIT_SUCCESS;
}
