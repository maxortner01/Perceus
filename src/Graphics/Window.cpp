#include "Perceus/Perceus.h"

#include "Perceus/Graphics/OpenGL/inc.h"

#include <iostream>

namespace pcs
{
    void Window::hello() const
    {
        std::cout << "hello\n";

        GLFWwindow* window = (GLFWwindow*)api()->create_window(1920, 1080);

        while (!glfwWindowShouldClose(window))
        {
            glClear(GL_COLOR_BUFFER_BIT);

            glfwSwapBuffers(window);

            glfwPollEvents();
        }

        api()->terminate();
    }
}