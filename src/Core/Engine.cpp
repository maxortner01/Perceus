#include "Perceus/Core/Engine.h"

#include "Perceus/Util/Log.h"

#include "Perceus/Core/Graphics/Rendering/OpenAPI.h"

namespace pcs
{
    Engine::Engine()
    {
        values = {
            "Good",
            "Failed"
        };

        Log::init();
        PS_CORE_INFO("Logger initialized");

        PS_CORE_INFO("Engine initialized");

        bool success = Window::rendAPI()->initialize();
        if (success)
            PS_CORE_INFO("OpenGL Initialized Successfully");
        else
            PS_CORE_ERROR("Failure to initialize OpenGL");

        // Make variable size
        window = Window::Create(200, 400);
    }

    Engine::~Engine()
    {
        delete window;
        
        Window::rendAPI()->terminate();

        PS_CORE_WARN("Engine shutdown");
    }

    RenderStatus Engine::renderScene(Scene* scene) const
    {
        // render the scene

        scene->_render();
        window->render();

        return RenderStatus::GOOD;
    }
}