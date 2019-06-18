#include "Perceus/Core/Engine.h"

#include "Perceus/Util/Log.h"

#include "Perceus/Core/Graphics/Rendering/OpenAPI.h"
#include "Perceus/Core/Graphics/Rendering/Events/EventHandler.h"

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
        window = Window::Create(400, 400);
    }

    Engine::~Engine()
    {
        delete window;
        
        Window::rendAPI()->terminate();

        PS_CORE_WARN("Engine shutdown");
    }

    RenderStatus Engine::renderScene(Scene* scene) const
    {
        static int frame;

        double start_time = rendAPI()->getTime();

        // render the scene
        EventHandler::get().clearEvents();
        window->pollEvents();
        scene->_render();
        window->render();

        // Frame calculations
        {
            static double totalElapsed = 0;
            double elapsed = rendAPI()->getTime() - start_time;
            totalElapsed += elapsed;

            if (frame == 120)
            {
                float fps = 120.f / totalElapsed;

                PS_CORE_DEBUG("120 frames passed with average fps of {0}", fps);

                frame = 0;
                totalElapsed = 0;
            }
        }

        frame++;

        return RenderStatus::GOOD;
    }
}