#include <ShaderPart.h>

std::string read_file(const std::string& file_path) {
    std::ifstream file(file_path, std::ios::binary);

    if (file.is_open()) {
        std::stringstream buffer;
        buffer << file.rdbuf();
        file.close();
        return buffer.str();
    } else {
        std::cerr << "Erro ao abrir o arquivo: " << file_path << std::endl;
        return std::string();
    }
}

ShaderPart::ShaderPart(string file_path, GLuint type)
{

    if (file_path.empty())
    {
        throw runtime_error("file_path is empty.");
    }

    string shader_source = read_file(file_path);

    if (shader_source.empty())
    {
        throw runtime_error("shader_source is empty from path " + file_path + ".");
    }

    const char* shader_source_c_str = shader_source.c_str();

    const GLint length = shader_source.length();

    id = glCreateShader(type);

    glShaderSource(id, 1, &shader_source_c_str, &length);

    glCompileShader(id);


    GLint success;

    glGetShaderiv(id, GL_COMPILE_STATUS, &success);

    if (!success)
    {

        GLint info_log_length;
        glGetShaderiv(id, GL_INFO_LOG_LENGTH, &info_log_length);

        std::vector<GLchar> info_log(info_log_length);
        glGetShaderInfoLog(id, info_log_length, NULL, info_log.data());


        throw runtime_error("error compiling shader from path "  + file_path + ":\n" + info_log.data());

    }

}

ShaderPart::~ShaderPart()
{
    glDeleteShader(id);
}