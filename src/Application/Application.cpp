#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
//#include <ImGUI/imgui.h>
//#include <ImGUI/imgui_impl_glfw_gl3.h>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include "Application.h"
#include "Renderer.h"
#include "Vertex_buffer.h"
#include "Index_buffer.h"
#include "Vertex_array.h"
#include "Shader.h"
#include "Shapes.h"

extern int app(ppd* pos) {
    GLFWwindow* window;

    if (!glfwInit())
        return -1;

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    const GLFWvidmode* mode = glfwGetVideoMode(glfwGetPrimaryMonitor());

    float window_width = mode->width;
    float window_height = mode->height;

    //std::cout << "Screen width: " << window_width << ", Screen height : " << window_height << std::endl;

    window = glfwCreateWindow(window_width, window_height, "Open GL test", NULL, NULL);
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
        const int npos = 100;
        const int nind = 99;

        std::vector <float> Pos = Shape::vertexOfCircle(100.0f, npos-1);
        float positions[npos * 2];
        for (int i = 0; i < npos*2; i++) {
            positions[i] = Pos[i];
        }

        std::vector <int> Ind = Shape::indexOfCircle(nind);
        unsigned int indices[nind * 3];
        for (int i = 0; i < nind*3; i++) {
            indices[i] = Ind[i];
        }

        Vertex_Array va;
        Vertex_Buffer vb(positions, npos * 2 * sizeof(float));

        VertexBufferLayout layout;
        layout.Push<float>(2);
        va.AddBuffer(vb, layout);

        Index_Buffer ib(indices, nind*3);

        glm::mat4 proj = glm::ortho(0.0f, window_width, 0.0f, window_height, -1.0f, 1.0f);
        glm::mat4 view = glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, 0));

        Shader shader("res/shaders/Basic.shader");
        shader.Bind();
        shader.SetUniform4f("u_Color", 0.2f, 0.3f, 0.8f, 0.1f);
        
        va.Unbind();
        shader.Unbind();
        vb.Unbind();
        ib.Unbind();

        Renderer renderer;

        //IMGUI_CHECKVERSION();
        //ImGui::CreateContext();
        //ImGuiIO& io = ImGui::GetIO(); (void)io;

        //ImGui_ImplGlfwGL3_Init(window, true);
        //ImGui::StyleColorsDark();

        glm::vec3 translation(200, 100, 0);

        while (!glfwWindowShouldClose(window)) {
            renderer.Clear();

            //ImGui_ImplGlfwGL3_NewFrame();

            glm::mat4 model = glm::translate(glm::mat4(1.0f), translation);
            glm::mat4 MVP = proj * view * model;

            shader.Bind();
            shader.SetUniform4f("u_Color", 0.0f, 0.3f, 0.8f, 0.1f);
            shader.SetUniformMat4f("u_MVP", MVP);

            renderer.Draw(va, ib, shader);
            GLCall(glDrawElements(GL_TRIANGLES, nind, GL_UNSIGNED_INT, nullptr));

            translation = { pos->first.first,pos->first.second,0 };

            /* {
                ImGui::SliderFloat3("Translation", &translation.x, 0.0f, 960.0f);
                ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
            }*/

            //ImGui::Render();
            //ImGui_ImplGlfwGL3_RenderDrawData(ImGui::GetDrawData());

            glfwSwapBuffers(window);
            glfwPollEvents();
        }
    }
    //ImGui_ImplGlfwGL3_Shutdown();
    //ImGui::DestroyContext();
    glfwTerminate();
    return 0;
}