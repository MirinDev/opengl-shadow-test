#include <ShaderPart.h>

string read_file(string file_path)
{
    fstream file;
    file.open(file_path);

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

    GLint success;
    glGetShaderiv(id, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        GLint log_len = 0;
        glGetShaderiv(id, GL_INFO_LOG_LENGTH, &log_len);

        string log;
        log.resize(log_len);

        glGetShaderInfoLog(id, log_len, NULL, &log[0]);

        cout << "error in file \"" << file_path << "\": " << endl << log << endl;
    }
}

ShaderPart::~ShaderPart()
{
    glDeleteShader(id);
}