#include <Shader.h>

Shader::Shader(vector<ShaderPart*> parts)
{
    id = glCreateProgram();

    for (int i = 0; i < parts.size(); i++)
    {
        ShaderPart* part = parts[i];

        glAttachShader(id, part->id);
    }

    glLinkProgram(id);

    GLint success;
    glGetProgramiv(id, GL_LINK_STATUS, &success);
    if (!success)
    {
        GLint log_len = 0;
        glGetProgramiv(id, GL_INFO_LOG_LENGTH, &log_len);

        string log;
        log.resize(log_len);

        glGetProgramInfoLog(id, log_len, NULL, &log[0]);

        cout << "error in shader: " << endl << log << endl;
    }
}

Shader::~Shader()
{
    glDeleteProgram(id);
}

void Shader::use()
{
    glUseProgram(id);
}