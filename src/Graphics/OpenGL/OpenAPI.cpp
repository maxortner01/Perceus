#include "Perceus/Perceus.h"

#include "Perceus/Graphics/OpenGL/inc.h"

#include <iostream>

namespace pcs
{
namespace rend
{
    void OpenAPI::init() const
    {
        PERC_ASSERT(glfwInit());
    }

    void OpenAPI::terminate() const
    {
        glfwTerminate();
    }

    void OpenAPI::make_context_current(void* context) const
    {
        glfwMakeContextCurrent((GLFWwindow*)context);
    }

    void* OpenAPI::create_window(const unsigned int width, const unsigned int height) const
    {
        init();

        GLFWwindow* window = glfwCreateWindow(width, height, "", NULL, NULL);
        PERC_ASSERT(window);

        make_context_current((void*)window);

        PERC_ASSERT(glewInit() == GLEW_OK)

        return (void*)window;
    }
}
}