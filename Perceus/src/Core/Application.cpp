#include "Perceus/Core/Application.h"

#include "Perceus/Util/Log.h"

namespace pcs
{
    void Application::pushScene(Scene* s)
    {
        PS_CORE_DEBUG("Pushing Scene to Application");
        scenes.push(s);
    }

    Application::Application(const unsigned int width, const unsigned int height) :
        engine(new Engine())
    {
<<<<<<< HEAD
        engine = &Engine::get();
=======
>>>>>>> master
        PS_CORE_DEBUG("Constructing Application");

        getValues() = {
            "Reached end of Program",
            "No Scenes"
        };
<<<<<<< HEAD
=======
        
        engine->getWindow()->resize(width, height);
>>>>>>> master
    }

    Application::~Application()
    {
        for (int i = 0; i < scenes.size(); i++)
        {
            delete scenes.top();
            scenes.pop();
        }

        delete engine;
    }

    int Application::run()
    {
        if (scenes.size() == 0) return (int)ExitCode::NoScenes;
        
        PS_CORE_DEBUG("Running application");
<<<<<<< HEAD
        engine->getWindow()->resize(1280, 720);
=======
>>>>>>> master
        while (engine->getWindow()->isOpen())
        {
            if (scenes.top()->getStatus() == pcs::SceneState::Finished)
                scenes.pop();
<<<<<<< HEAD

=======
                
>>>>>>> master
            if (scenes.size() == 0) break;
            
            engine->renderScene(scenes.top());
        }

        // while window is open
        //   if state of scene is finished,
        //     remove first item of scenes and move all items up
        //   else if error 
        //     exit program
        //
        //   render the scene

        return (int)ExitCode::EndOfProgram;
    }
}