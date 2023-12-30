#include "VertexBufferLayout.h"

#include "Renderer.h"

unsigned int VertexBufferElement::GetSizeOfType(unsigned int type) {//buffer layout for each element
	switch (type) {
	case GL_FLOAT: return 4;
	case GL_UNSIGNED_INT: return 4;
	case GL_UNSIGNED_BYTE: return 1;
	}
	ASSERT(false);
	return 0;
}

template<typename>
constexpr bool dependent_false = false;

template <typename T>
void VertexBufferLayout::Push(unsigned int count) {
	static_assert(dependent_false<T>);
}

//different type layout for every type that is accepted
template<>
void VertexBufferLayout::Push<float>(unsigned int count) {
	m_Elements.push_back({ GL_FLOAT, count, GL_FALSE });
	m_Stride += count * VertexBufferElement::GetSizeOfType(GL_FLOAT);
}
template<>
void VertexBufferLayout::Push <unsigned int>(unsigned int count) {
	m_Elements.push_back({ GL_UNSIGNED_INT, count, GL_FALSE });
	m_Stride += count * VertexBufferElement::GetSizeOfType(GL_UNSIGNED_INT);
}

template<>
void VertexBufferLayout::Push <unsigned char>(unsigned int count) {
	m_Elements.push_back({ GL_UNSIGNED_BYTE, count, GL_TRUE });
	m_Stride += count * VertexBufferElement::GetSizeOfType(GL_UNSIGNED_BYTE);
}

const std::vector<VertexBufferElement> VertexBufferLayout::GetElements() const {
	return m_Elements;
}

unsigned int VertexBufferLayout::GetStride() const {
	return m_Stride;
}