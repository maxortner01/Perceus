#include "Perceus/Core/Graphics/Rendering/Events/EventHandler.h"
#include "Perceus/Core/Graphics/Rendering/Events.h"

#include "Perceus/Core/Graphics/Rendering/OpenAPI.h"
#include "Perceus/Core/Graphics/Window.h"
#include "Perceus/Util/Log.h"

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

    int OpenAPI::makeWindow(void* windowPTR)
    {
        Window* window = (Window*)windowPTR;

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

    int OpenAPI::destroyWindow(void* windowPTR)
    {
        Window* window = (Window*)windowPTR;

        glfwDestroyWindow((GLFWwindow*)*window->getAPILoc());

        return true;
    }

    bool OpenAPI::shouldClose(void* windowPTR) const
    {
        Window* window = (Window*)windowPTR;

        return glfwWindowShouldClose((GLFWwindow*)*window->getAPILoc());
    }

    bool OpenAPI::swapBuffers(void* windowPTR) const
    {
        Window* window = (Window*)windowPTR;

        glfwSwapBuffers((GLFWwindow*)*window->getAPILoc());

        return true;
    }

    bool OpenAPI::pollEvents(void* windowPTR) const
    {
        glfwPollEvents();

        return true;
    }

    bool OpenAPI::resizeWindow(void* windowPTR, unsigned int width, unsigned int height) const
    {
        Window* window = (Window*)windowPTR;

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
        glBegin(GL_TRIANGLES);
        glColor3f(1, 0, 0);

        glVertex2f(-.5f, -.5f);
        glVertex2f(.5f, -.5f);
        glVertex2f(0, .5f);

        glEnd();
    }

    bool OpenAPI::clear(Color color) const
    {
        glClearColor(color.r, color.g, color.b, color.a);
        glClear(GL_COLOR_BUFFER_BIT);

        return true;
    }
}
}