#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include "Renderer.h"
#include "Vertex_buffer.h"
#include "Index_buffer.h"
#include "Vertex_array.h"
#include "Shader.h"

static int app(){
    GLFWwindow* window;

    if (!glfwInit())
        return -1;

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

   window = glfwCreateWindow(6480, 3860, "Open GL test", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);

    if (glewInit() != GLEW_OK) {
        std::cout << "GLEW initialisation failed" << "\n";
    }

    GLCall(std::cout << glGetString(GL_VERSION) << std::endl);
    {
        float positions[8] = {
            -0.5f, -0.5f,
            0.5f, -0.5f,
            0.5f, 0.5f,
            -0.5f, 0.5f,
        };

        unsigned int indices[6] = {
            0, 1, 2,
            2, 3, 0
        };
        
        Vertex_Array va;
        Vertex_Buffer vb(positions, 4 * 2 * sizeof(float));

        VertexBufferLayout layout;
        layout.Push<float>(2);
        va.AddBuffer(vb, layout);

        Index_Buffer ib(indices, 6);

        glm::mat4 proj = glm::ortho(-2.0f, 2.0f, -1.5f, 1.5f, -1.0f, 1.0f);

        Shader shader("res/shaders/Basic.shader");
        shader.Bind();
        shader.SetUniform4f("u_Color", 0.2f, 0.3f, 0.8f, 0.1f);
        shader.SetUniformMat4f("u_MVP", proj);

        va.Unbind();
        shader.Unbind();
        vb.Unbind();
        ib.Unbind();
        
        Renderer renderer;

        while (!glfwWindowShouldClose(window)){
            renderer.Clear();

            shader.Bind();
            shader.SetUniform4f("u_Color", 0.0f, 0.3f, 0.8f, 0.1f);

            renderer.Draw(va,ib,shader);
            GLCall(glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr));

            glfwSwapBuffers(window);
            glfwPollEvents();
        }
    }
    glfwTerminate();
    return 0;
}