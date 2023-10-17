#pragma once

class Index_Buffer {
private:
	unsigned int m_rendererID;
	unsigned int m_count;
public:
	Index_Buffer(const unsigned int* data, unsigned int count);
	~Index_Buffer();

	void Bind() const;
	void Unbind() const;

	inline unsigned int GetCount() const { return m_count; }
};