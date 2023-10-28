#pragma once

#include <string>

class Vertex_Buffer {
private:
	unsigned int m_rendererID;
public:
	Vertex_Buffer(const void* data, unsigned int size, std::string type);
	~Vertex_Buffer();

	void Sub(const void* data, unsigned int size);

	void Bind() const;
	void Unbind() const;
};