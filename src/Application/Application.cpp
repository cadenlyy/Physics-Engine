#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
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

    //Check is glfw can be run
    if (!glfwInit())
        return -1;

    //set OpenGL version and type
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    //getting Screen resolution
    const GLFWvidmode* mode = glfwGetVideoMode(glfwGetPrimaryMonitor());

    app.Width = mode->width;
    app.Height = mode->height;

    //create Application window
    window = glfwCreateWindow(app.Width, app.Height, "Physics Engine", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);

    //Check id glew can be run
    if (glewInit() != GLEW_OK) {
        std::cout << "GLEW initialisation failed" << "\n";
    }

    //Outputing Version of OpenGL being used
    GLCall(std::cout << glGetString(GL_VERSION) << std::endl);

    {
        //increment lines (draws line of increments of 1 cm, takes 100 pixels to be 1cm)
        std::vector <float> PosIncr;
        //verticle lines
        for (int i = 1; i <= app.Width; i+=100) { //increment till it reaches the screen width
            //vertex positions of a rect
            PosIncr.push_back(i); PosIncr.push_back(0);
            PosIncr.push_back(i); PosIncr.push_back(app.Height);
            PosIncr.push_back(i + 1.0f); PosIncr.push_back(app.Height);
            PosIncr.push_back(i + 1.0f); PosIncr.push_back(0);
        }
        //horizontal lines
        for (int i = 1; i <= app.Height; i+=100) { //increment till it reaches the screen height
            //vertex positions of a rect
            PosIncr.push_back(0); PosIncr.push_back(i);
            PosIncr.push_back(app.Width); PosIncr.push_back(i);
            PosIncr.push_back(app.Width); PosIncr.push_back(i + 1.0f);
            PosIncr.push_back(0); PosIncr.push_back(i + 1.0f);
        }

        //creating indecies for increent lines
        std::vector <unsigned int> IndexIncr;
        for (int i = 0; i < PosIncr.size()/4; i++) { //increment till all Vertex Position are used
            IndexIncr.push_back((4 + i * 4) - 4); IndexIncr.push_back((4 + i * 4) - 3); IndexIncr.push_back((4 + i * 4) - 2); //triangle 1
            IndexIncr.push_back((4 + i * 4) - 4); IndexIncr.push_back((4 + i * 4) - 2); IndexIncr.push_back((4 + i * 4) - 1); //triangle 2
        }

        Vertex_Array vaIncr; 
        Vertex_Buffer vbIncr(&PosIncr.front(), PosIncr.size() * sizeof(float), "STATIC"); //static vertex buffer

        VertexBufferLayout layoutIncr;
        layoutIncr.Push<float>(2);//layout of buffer is just x and y coords of vertex position
        vaIncr.AddBuffer(vbIncr, layoutIncr);

        Index_Buffer ibIncr(&IndexIncr.front(), IndexIncr.size());

        glm::mat4 projIncr = glm::ortho(0.0f, app.Width, 0.0f, app.Height, -1.0f, 1.0f); //projecting Increment lines to size of window

        Shader shaderIncr("res/shaders/Basic.shader");
        shaderIncr.Bind();
        shaderIncr.SetUniform4f("u_Color", 0.25f, 0.25f, 0.25f, 0.1f); //drawing the lines in light gray color

        vaIncr.Unbind();
        shaderIncr.Unbind();
        vbIncr.Unbind();
        ibIncr.Unbind();

        //object

        std::vector <float> Pos = Object1->VertexPos;//defining the vector for vertex positions

        std::vector <unsigned int> Ind = Object1->IndexPos;//defining the vector for vertex positions
        //std::vector <unsigned int> Ind = { 6 + 8,6 + 9,6 + 10 };

        Vertex_Array va;
        Vertex_Buffer vb(nullptr, Pos.size() * sizeof(float), "DYNAMIC");//creates a dynamic vertex buffer without any values

        VertexBufferLayout layout;
        layout.Push<float>(2);//layout of buffer is just x and y coords of vertex position
        va.AddBuffer(vb, layout);

        Index_Buffer ib(&Ind.front(), Ind.size());

        glm::mat4 proj = glm::ortho(0.0f, app.Width, 0.0f, app.Height, -1.0f, 1.0f); //projection matrix to project to the window size
        glm::mat4 view = glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, 0)); // view matrix to simulate the movement of a camera
        glm::mat4 model = glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, 0)); //model matrix to move the whole model(vertex ositions of individual objects are edited in the Physics engine and put into the dynamic Vertex Buffer)

        Shader shader("res/shaders/Basic.shader");
        shader.Bind();
        shader.SetUniform4f("u_Color", Object1->Color[0], Object1->Color[1], Object1->Color[2], Object1->Color[3]);//draw all objects what ever colour was defines in the object
        
        va.Unbind();
        shader.Unbind();
        vb.Unbind();
        ib.Unbind();

        Renderer renderer;

        while (!glfwWindowShouldClose(window)) {
            renderer.Clear(); //clearing screen

            glm::mat4 MVPIncr = projIncr;//creating MVP matrix for increment line(only have Projection and the lines dont move so there is no need for model and there in no camera now so there is no need for view)
            shaderIncr.Bind();
            shaderIncr.SetUniformMat4f("u_MVP", MVPIncr);

            renderer.Draw(vaIncr, ibIncr, shaderIncr);//drawing increment lines
            
            if(!Object1->VertexPos.empty()) Pos = Object1->VertexPos;//check is VertexPos of object is empty incase the CPU in taking a while to edit the vector and it happens to be empty when this is called
            vb.Bind();
            if (!Pos.empty()) vb.Sub(&Pos.front(), Pos.size() * sizeof(float)); //ensuring Pos is not empty when this is called in case of the editing of it being slow and it still being empty

            glm::mat4 MVP = proj * view * model;//MPV matrix(there is no actuall need ofr the view matrix as there is no camera movement
            shader.Bind();
            shader.SetUniformMat4f("u_MVP", MVP);
                
            renderer.Draw(va, ib, shader);//drawing objects

            GLCall(glDrawElements(GL_TRIANGLES, Object1->IndexPos.size(), GL_UNSIGNED_INT, nullptr));//drawing everything on the window

            glfwSwapBuffers(window);
            glfwPollEvents();
        }
    }
    glfwTerminate();//stopping the app
    return 0;
}