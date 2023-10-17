#include "Index_buffer.h"

#include "Renderer.h"

Index_Buffer::Index_Buffer(const unsigned int* data, unsigned int count) :m_count(count){
    

    GLCall(glGenBuffers(1, &m_rendererID));
    GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_rendererID));
    GLCall(glBufferData(GL_ELEMENT_ARRAY_BUFFER, count*(sizeof(unsigned int)), data, GL_STATIC_DRAW));

}

Index_Buffer::~Index_Buffer(){
    GLCall(glDeleteBuffers(1, &m_rendererID));
}

void Index_Buffer::Bind() const {
    GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_rendererID));
}

void Index_Buffer::Unbind() const {
    GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
}
