#pragma once

class Vertex_Buffer {
private:
	unsigned int m_rendererID;
public:
	Vertex_Buffer(const void* data, unsigned int size);
	~Vertex_Buffer();

	void Bind() const;
	void Unbind() const;
};