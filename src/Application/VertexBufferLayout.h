#pragma once
#include<vector>
#include<GL/glew.h>

struct VertexBufferElement {
	unsigned int type;
	unsigned int count;
	unsigned char normalised;
	static unsigned int GetSizeOfType(unsigned int type);
};

class VertexBufferLayout{
private:
	std::vector<VertexBufferElement> m_Elements;
	unsigned int m_Stride;
public:
	VertexBufferLayout(): m_Stride(0) {}
	template <typename T>
	void Push(unsigned int count);
	template<>
	void Push <float>(unsigned int count);
	template<>
	void Push <unsigned int>(unsigned int count);

	template<>
	void Push <unsigned char>(unsigned int count);

	const std::vector<VertexBufferElement> GetElements() const;

	unsigned int GetStride() const;
};

