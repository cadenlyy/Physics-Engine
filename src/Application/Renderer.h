#pragma once
#include <GL/glew.h>

#include "Vertex_array.h"
#include "Index_buffer.h"
#include "Shader.h"



#define ASSERT(x) if(!(x)) __debugbreak();
//asserting at line where there is errors
#define GLCall(x) GLClearError();\
    x;\
    ASSERT(GLLogError(#x, __FILE__, __LINE__));

void GLClearError();

bool GLLogError(const char* func, const char* file, int line);

class Renderer {
public:
    void Clear() const;
    void Draw(const Vertex_Array& va, const Index_Buffer& ib, const Shader& shader) const;
};
