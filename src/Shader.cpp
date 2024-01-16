#include <Shader.h>

Shader::Shader(vector<ShaderPart*> parts)
{
    id = glCreateProgram();

    /* This should ideally be temporary and take the parts and then compile them into a specific function. */

        if (!parts.empty())
        {

            for (int i = 0; i < parts.size(); i++)
            {
                ShaderPart* part = parts[i];

                glAttachShader(id, part->id);
            }

            glLinkProgram(id);

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