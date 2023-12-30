#include <GL/glew.h>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include "Shader.h"
#include "Renderer.h"



Shader::Shader(const std::string& filepath) : m_FilePath(filepath), m_RendererID(0){//constructor
    ShaderProgramSource source = ParseShader(filepath);
    m_RendererID = CreateShader(source.VertexSource, source.FragmentSource);
}

Shader::~Shader(){//destructor
    GLCall(glDeleteProgram(m_RendererID));

}



ShaderProgramSource Shader::ParseShader(const std::string& filepath) {//getting shader source code
    std::ifstream stream(filepath);//getting file

    enum class ShaderType {
        NONE = -1, VERTEX = 0, FRAGMENT = 1
    };

    std::string line;
    ShaderType type = ShaderType::NONE;
    std::stringstream ss[2];
    while (getline(stream, line)) {
        if (line.find("#shader") != std::string::npos) {//checking for shader
            if (line.find("vertex") != std::string::npos) {//checking if its the vertex shader
                type = ShaderType::VERTEX;//setting type to vertex
            }
            else if (line.find("fragment") != std::string::npos) {//checking if its the vertex shader
                type = ShaderType::FRAGMENT;//setting type to fragment
            }
        }
        else {
            ss[(int)type] << line << '\n';//getting shader code
        }
    }
    return { ss[0].str(), ss[1].str() };
}

unsigned int Shader::CompileShader(unsigned int type, const std::string& source) {
    GLCall(unsigned int id = glCreateShader(type));
    const char* src = source.c_str();//putting the shader code into variable
    GLCall(glShaderSource(id, 1, &src, nullptr));
    GLCall(glCompileShader(id));

    int result;
    GLCall(glGetShaderiv(id, GL_COMPILE_STATUS, &result));//checking if shader works
    if (result == GL_FALSE) {
        int length;
        GLCall(glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length));
        char* message = (char*)alloca(length * sizeof(char));
        GLCall(glGetShaderInfoLog(id, length, &length, message));
        GLCall(std::cout << "Failed to compile " << (type == GL_VERTEX_SHADER ? "vertex" : "fragment") << "shader" << std::endl);
        std::cout << message << std::endl; //outputing the error with the shader
        GLCall(glDeleteShader(id));
        return 0;
    }

    return id;
}

unsigned int Shader::CreateShader(const std::string& vertexShader, const std::string& fragmentShader) {//creating shader with vertex and fragment shader together
    GLCall(unsigned int program = glCreateProgram());
    GLCall(unsigned int vs = CompileShader(GL_VERTEX_SHADER, vertexShader));
    GLCall(unsigned int fs = CompileShader(GL_FRAGMENT_SHADER, fragmentShader));

    GLCall(glAttachShader(program, vs));
    GLCall(glAttachShader(program, fs));
    GLCall(glLinkProgram(program));
    GLCall(glValidateProgram(program));

    GLCall(glDeleteShader(vs));
    GLCall(glDeleteShader(fs));

    return program;
}

void Shader::Bind() const{
    GLCall(glUseProgram(m_RendererID));
}

void Shader::Unbind() const{
    GLCall(glUseProgram(0));
}

void Shader::SetUniform4f(const std::string& name, float v0, float v1, float f2, float f3){//setting uniform for colour
    GLCall(glUniform4f(GetUniformLoction(name), v0, v1, f2, f3));
}

void Shader::SetUniformMat4f(const std::string& name, const glm::mat4& matrix){//setting uniform for position
    GLCall(glUniformMatrix4fv(GetUniformLoction(name), 1, GL_FALSE, &matrix[0][0]));
}

unsigned int Shader::GetUniformLoction(const std::string& name) {
    if (m_UniformLocationCache.find(name) != m_UniformLocationCache.end()) {//checking if uniform can be found
        return m_UniformLocationCache[name];
    }
    GLCall(int location = glGetUniformLocation(m_RendererID, name.c_str()));
    if (location == -1) {
        std::cout << "Warning: uniform " << name << " doesn't exist" << std::endl;//outputing error
    }
    m_UniformLocationCache[name] = location;
    return location;
}
