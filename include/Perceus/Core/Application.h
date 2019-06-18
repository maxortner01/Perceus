#pragma once

#include "Scene.h"
#include "Engine.h"

#include <vector>

namespace pcs
{
    
    // Exit Code
    enum class ExitCode
    {
        END_OF_PROGRAM,
        NO_SCENES
    };

    // Strings for exit codes
    const char* getExitValue(int enumVal)
    {
        return (const char *[])
        {
            "Reached end of Program",
            "No Scenes to Render"
        }[enumVal];
    }

    class Application
    {
        friend class Scene;

        // Window instance
        Engine* engine;

        // Stack of scenes to render, only renders the
        // first item in this list
        std::vector<Scene*> scenes;

    protected:
        void pushScene(Scene* s);

    public:
        Application();

        // Handle engine and scene deletion
        virtual ~Application();

        // Initialize the engine and run the application
        int run();
    };

    // To be defined by the client
    Application* CreateApplication();
}