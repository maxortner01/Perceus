#include "Perceus/Core/Graphics/Rendering/OpenAPI.h"
#include "Perceus/Core/Graphics/Window.h"

#include <iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace pcs
{
namespace rend
{
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

    bool OpenAPI::resizeWindow(void* windowPTR, unsigned int width, unsigned int height) const
    {
        Window* window = (Window*)windowPTR;

        glfwSetWindowSize((GLFWwindow*)*window->getAPILoc(), width, height);

        return true;
    }

    bool OpenAPI::clear(Color color) const
    {
        glClearColor(color.r, color.g, color.b, color.a);
        glClear(GL_COLOR_BUFFER_BIT);

        return true;
    }
}
}