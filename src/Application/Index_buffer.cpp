#include "Index_buffer.h"

#include "Renderer.h"

Index_Buffer::Index_Buffer(const unsigned int* data, unsigned int count) :m_count(count){//constructor
    GLCall(glGenBuffers(1, &m_rendererID));
    GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_rendererID));
    GLCall(glBufferData(GL_ELEMENT_ARRAY_BUFFER, count*(sizeof(unsigned int)), data, GL_STATIC_DRAW));//putting data into the buffer
}

Index_Buffer::~Index_Buffer(){//destructor
    GLCall(glDeleteBuffers(1, &m_rendererID));
}

void Index_Buffer::Bind() const {
    GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_rendererID));
}

void Index_Buffer::Unbind() const {
    GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
}
