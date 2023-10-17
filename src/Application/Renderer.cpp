#include <iostream>
#include <GL/glew.h>

#include "Renderer.h"

void GLClearError() {
    while (glGetError() != GL_NO_ERROR);
}

bool GLLogError(const char* func, const char* file, int line) {
    while (GLenum error = glGetError()) {
        std::cout << "[OpenGL error] (" << error << "): " << file << " (line: " << line << "): " << func << std::endl;
        return false;
    }
    return true;
}

void Renderer::Clear() const{
    GLCall(glClear(GL_COLOR_BUFFER_BIT));
}

void Renderer::Draw(const Vertex_Array& va, const Index_Buffer& ib, const Shader& shader) const{
    shader.Bind();
    va.Bind();
    ib.Bind();
    GLCall(glDrawElements(GL_TRIANGLES, ib.GetCount(), GL_UNSIGNED_INT, nullptr));
}
