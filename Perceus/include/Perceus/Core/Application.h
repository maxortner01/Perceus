#pragma once

#include "Engine.h"

#include "Perceus/Data/Status.h"
#include "Perceus/Data/Inc.h"

namespace pcs
{
    
    // Exit Code
    enum class ExitCode
    {
        EndOfProgram,
        NoScenes
    };

    /**
     * @brief Handles and runs the entire engine process.
     * This is where the main loop is, this holds the engine.
     * 
     */
<<<<<<< HEAD
    class Application : public Data::Status<ExitCode>
=======
    class PERC_API Application : public Data::Status<ExitCode>
>>>>>>> master
    {
        friend class Scene;

        // Engine instance
        Engine* engine;

        // Stack of scenes to render, only renders the
        // first item in this list
        std::stack<Scene*> scenes;
<<<<<<< HEAD
        //std::vector<Scene*> scenes;
=======
>>>>>>> master

    protected:
        void pushScene(Scene* s);

    public:
        Application(const unsigned int width, const unsigned int height);

        // Handle engine and scene deletion
        virtual ~Application();

        // Initialize the engine and run the application
        int run();

        Window &getCurrentWindow() { return *engine->getWindow(); }
    };

    // To be defined by the client
    Application* CreateApplication();
}