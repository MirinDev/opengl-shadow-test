#include <ShaderPart.h>

string read_file(string file_path)
{
    fstream file(file_path, ios::binary);

    if (file)
    {
        string data;

        file.seekg(0, std::ios::end);
		data.resize(file.tellg());
		file.seekg(0, std::ios::beg);

		file.read(&data[0], data.size());
		file.close();

        return data;
    }
    
    return "";
}

ShaderPart::ShaderPart(string file_path, GLuint type)
{
    string shader_string = read_file(file_path);
    const char* shader_code = shader_string.c_str();

    id = glCreateShader(type);
    glShaderSource(id, 1, &shader_code, NULL);
    glCompileShader(id);
}

ShaderPart::~ShaderPart()
{
    glDeleteShader(id);
}