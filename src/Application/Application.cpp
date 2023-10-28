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
#include "Physics/Vec2d.h"
#include "Objects.h"

extern int app(Object* Object1) {
    GLFWwindow* window;

    Window app;

    if (!glfwInit())
        return -1;

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    const GLFWvidmode* mode = glfwGetVideoMode(glfwGetPrimaryMonitor());


    app.Width = mode->width;
    app.Height = mode->height;

    window = glfwCreateWindow(app.Width, app.Height, "Open GL test", NULL, NULL);
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
        //increment lines
        std::vector <float> PosIncr;
        for (int i = 1; i <= app.Width; i+=100) {
            PosIncr.push_back(i); PosIncr.push_back(0);
            PosIncr.push_back(i); PosIncr.push_back(app.Height);
            PosIncr.push_back(i + 1.0f); PosIncr.push_back(app.Height);
            PosIncr.push_back(i + 1.0f); PosIncr.push_back(0);
        }
        for (int i = 1; i <= app.Height; i+=100) {
            PosIncr.push_back(0); PosIncr.push_back(i);
            PosIncr.push_back(app.Width); PosIncr.push_back(i);
            PosIncr.push_back(app.Width); PosIncr.push_back(i + 1.0f);
            PosIncr.push_back(0); PosIncr.push_back(i + 1.0f);
        }

        std::vector <unsigned int> IndexIncr;
        for (int i = 0; i < PosIncr.size(); i++) {
            IndexIncr.push_back((4 + i * 4) - 4); IndexIncr.push_back((4 + i * 4) - 3); IndexIncr.push_back((4 + i * 4) - 2);
            IndexIncr.push_back((4 + i * 4) - 4); IndexIncr.push_back((4 + i * 4) - 2); IndexIncr.push_back((4 + i * 4) - 1);
        }

        Vertex_Array vaIncr;
        Vertex_Buffer vbIncr(&PosIncr.front(), PosIncr.size() * sizeof(float), "STATIC");

        VertexBufferLayout layoutIncr;
        layoutIncr.Push<float>(2);
        vaIncr.AddBuffer(vbIncr, layoutIncr);

        Index_Buffer ibIncr(&IndexIncr.front(), IndexIncr.size());

        glm::mat4 projIncr = glm::ortho(0.0f, app.Width, 0.0f, app.Height, -1.0f, 1.0f);

        Shader shaderIncr("res/shaders/Basic.shader");
        shaderIncr.Bind();
        shaderIncr.SetUniform4f("u_Color", 0.25f, 0.25f, 0.25f, 0.1f);

        vaIncr.Unbind();
        shaderIncr.Unbind();
        vbIncr.Unbind();
        ibIncr.Unbind();

        //object

        std::vector <float> Pos = Object1->VertexPos;

        std::vector <unsigned int> Ind = Object1->IndexPos;
        //std::vector <unsigned int> Ind = { 4,5,6,4,6,7,4,7,5 };

        Vertex_Array va;
        Vertex_Buffer vb(nullptr, Pos.size() * sizeof(float), "DYNAMIC");

        VertexBufferLayout layout;
        layout.Push<float>(2);
        va.AddBuffer(vb, layout);

        Index_Buffer ib(&Ind.front(), Ind.size());

        glm::mat4 proj = glm::ortho(0.0f, app.Width, 0.0f, app.Height, -1.0f, 1.0f);
        glm::mat4 view = glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, 0));
        glm::mat4 model = glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, 0));

        Shader shader("res/shaders/Basic.shader");
        shader.Bind();
        shader.SetUniform4f("u_Color", Object1->Color[0], Object1->Color[1], Object1->Color[2], Object1->Color[3]);
        
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

        while (!glfwWindowShouldClose(window)) {
            renderer.Clear();

            //ImGui_ImplGlfwGL3_NewFrame();

            glm::mat4 MVPIncr = projIncr;
            shaderIncr.Bind();
            shaderIncr.SetUniformMat4f("u_MVP", MVPIncr);

            renderer.Draw(vaIncr, ibIncr, shaderIncr);
            
            std::vector <float> Pos = Object1->VertexPos;
            for (auto i : Pos) std::cout << i << '\n';
            vb.Bind();
            vb.Sub(&Pos.front(), Pos.size() * sizeof(float));

            glm::mat4 MVP = proj * view * model;
            shader.Bind();
            shader.SetUniformMat4f("u_MVP", MVP);
                
            renderer.Draw(va, ib, shader);

            GLCall(glDrawElements(GL_TRIANGLES, Object1->IndexPos.size(), GL_UNSIGNED_INT, nullptr));

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