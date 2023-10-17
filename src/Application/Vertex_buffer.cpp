#include "Vertex_buffer.h"

#include "Renderer.h"

Vertex_Buffer::Vertex_Buffer(const void* data, unsigned int size){
    GLCall(glGenBuffers(1, &m_rendererID));
    GLCall(glBindBuffer(GL_ARRAY_BUFFER, m_rendererID));
    GLCall(glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW));

}

Vertex_Buffer::~Vertex_Buffer(){
    GLCall(glDeleteBuffers(1, &m_rendererID));
}

void Vertex_Buffer::Bind() const{
    GLCall(glBindBuffer(GL_ARRAY_BUFFER, m_rendererID));
}

void Vertex_Buffer::Unbind() const{
    GLCall(glBindBuffer(GL_ARRAY_BUFFER, 0));
}
