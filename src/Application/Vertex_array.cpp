#include "Vertex_array.h"
#include "Renderer.h"

Vertex_Array::Vertex_Array() {
	GLCall(glGenVertexArrays(1, &m_RendererID));
}	

Vertex_Array::~Vertex_Array(){
	GLCall(glDeleteVertexArrays(1, &m_RendererID));
}

void Vertex_Array::AddBuffer(const Vertex_Buffer& vb, const VertexBufferLayout& layout){
	Bind();
	vb.Bind();
	const auto& elements = layout.GetElements();
	unsigned int offset = 0;
	for (unsigned int i = 0; i < elements.size(); i++) {
		const auto& element = elements[i];
		GLCall(glEnableVertexAttribArray(i));
		GLCall(glVertexAttribPointer(i, element.count, element.type, element.normalised, layout.GetStride(), (const void*)offset));
		offset += element.count*VertexBufferElement::GetSizeOfType(element.type);
	}
	
}

void Vertex_Array::Bind() const{
	GLCall(glBindVertexArray(m_RendererID));
}

void Vertex_Array::Unbind() const{
	GLCall(glBindVertexArray(0));
}
