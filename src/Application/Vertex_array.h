#pragma once

#include "Vertex_buffer.h"
#include "VertexBufferLayout.h"

class Vertex_Array{
private:
	unsigned int m_RendererID;
public:
	Vertex_Array();
	~Vertex_Array();

	void AddBuffer(const Vertex_Buffer& vb, const VertexBufferLayout& layout);
	void Bind() const;
	void Unbind() const;
};

