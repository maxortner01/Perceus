#include "Perceus/Core/Graphics/Rendering/Events/EventHandler.h"
#include "Perceus/Core/Graphics/Rendering/Events.h"

#include "Perceus/Core/Graphics/Rendering/BufferArray.h"
#include "Perceus/Core/Graphics/Rendering/OpenAPI.h"
#include "Perceus/Core/Graphics/Rendering/Buffer.h"
#include "Perceus/Core/Graphics/Window.h"
#include "Perceus/Util/Log.h"

#include "Perceus/Data/Vector.h"

#include <math.h>
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace pcs
{
namespace rend
{
    void window_close_callback(GLFWwindow* window)
    {
        EventHandler::get().pushEvent<WindowClosedEvent>();
    }

    void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
    {
        /**/ if (action == GLFW_PRESS)
            EventHandler::get().pushEvent<KeyPressEvent>(key);
        else if (action == GLFW_RELEASE)
            EventHandler::get().pushEvent<KeyReleaseEvent>(key);
        else if (action == GLFW_REPEAT)
            EventHandler::get().pushEvent<KeyDownEvent>(key);
    }

    bool OpenAPI::initialize()
    {
        if (!glfwInit())
            return false;

        return true;
    }

    bool OpenAPI::terminate()
    {
        glfwTerminate();

        return true;
    }

    int OpenAPI::makeWindow(Window* window)
    {
        *window->getAPILoc() = (void*)glfwCreateWindow(window->getSize().x, window->getSize().y, "Test", NULL, NULL);

        if (!window)
        {
            return (int)WindowStatus::WINDOW_CREATION_FAILED;
        }

        glfwMakeContextCurrent((GLFWwindow*)*window->getAPILoc());

        if (glewInit() != GLEW_OK)
        {
            return (int)WindowStatus::API_INIT_FAILED;
        }
        
        glfwSetWindowCloseCallback((GLFWwindow*)*window->getAPILoc(), window_close_callback);
        glfwSetKeyCallback((GLFWwindow*)*window->getAPILoc(), key_callback);

        return (int)WindowStatus::OK;
    }

    int OpenAPI::destroyWindow(Window* window)
    {
        glfwDestroyWindow((GLFWwindow*)*window->getAPILoc());

        return true;
    }

    bool OpenAPI::shouldClose(Window* window) const
    {

        return glfwWindowShouldClose((GLFWwindow*)*window->getAPILoc());
    }

    bool OpenAPI::swapBuffers(Window* window) const
    {
        glfwSwapBuffers((GLFWwindow*)*window->getAPILoc());

        return true;
    }

    bool OpenAPI::pollEvents(Window* window) const
    {
        glfwPollEvents();

        return true;
    }

    bool OpenAPI::resizeWindow(Window* window, unsigned int width, unsigned int height) const
    {
        glfwSetWindowSize((GLFWwindow*)*window->getAPILoc(), width, height);
        glViewport(0, 0, width, height); 

        return true;
    }

    double OpenAPI::getTime() const
    {
        return glfwGetTime();
    }

    void OpenAPI::test() const
    {
        static int frame;

        std::vector<float> vertices = {
            -.5f, -.5f,
             .5f, -.5f,
               0,  .5f
        };

        BufferArray bufferArray = BufferArray();
        bufferArray.bindBuffer(BufferIndex::Vertices, 2, vertices);


        bufferArray.getBuffer(BufferIndex::Vertices).bind();

        glDrawArrays(GL_TRIANGLES, 0, 3);

        bufferArray.getBuffer(BufferIndex::Vertices).unbind();

        //glBegin(GL_TRIANGLES);
//
        //glColor3f(1, 0, 0);
        //glVertex2f(-.5f, -.5f);
//
        //glColor3f(1, 1, 0);
        //glVertex2f(.5f, -.5f );
//
        //glColor3f(1, 0, 1);
        //glVertex2f(0, .5f);
//
        //glEnd();

        frame++;
    }

    bool OpenAPI::clear(Color color) const
    {
        glClearColor(color.r, color.g, color.b, color.a);
        glClear(GL_COLOR_BUFFER_BIT);

        return true;
    }

    void OpenAPI::makeBuffer(Buffer* buffer) const
    {
        glGenBuffers(1, &buffer->getID());
    }

    void OpenAPI::destroyBuffer(Buffer* buffer) const
    {
        glDeleteBuffers(1, &buffer->getID());
    }

    void OpenAPI::bindBuffer(unsigned int ID, BufferType type) const
    {
        GLenum t = GL_ARRAY_BUFFER;
        
        if (type == BufferType::Index) t = GL_ELEMENT_ARRAY_BUFFER;

        glBindBuffer(t, ID);
    }

    void OpenAPI::bindBufferData(unsigned int bytesize, const void* data, unsigned int members, unsigned int index, BufferType type) const
    {
        GLenum t = GL_ARRAY_BUFFER;
        
        if (type == BufferType::Index) t = GL_ELEMENT_ARRAY_BUFFER;

        glBufferData(t, bytesize, data, GL_STATIC_DRAW);

        glEnableVertexAttribArray(index);
        glVertexAttribPointer(index, members, GL_FLOAT, GL_FALSE, 0, 0);
    }

    void OpenAPI::makeBufferArray(BufferArray* array) const
    {
        glGenVertexArrays(1, &array->getID());
    }

    void OpenAPI::destroyBufferArray(BufferArray* array) const
    {
        glDeleteVertexArrays(1, &array->getID());
    }
}
}