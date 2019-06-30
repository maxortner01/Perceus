#include "Perceus/Core/Application.h"

#include "Perceus/Util/Log.h"

namespace pcs
{
    void Application::pushScene(Scene* s)
    {
        scenes.push_back(s);
    }

    Application::Application()
    {
        engine = &Engine::get();
    }

    Application::~Application()
    {
        for (int i = 0; i < scenes.size(); i++)
            delete scenes[i];

        delete engine;
    }

    int Application::run()
    {
        if (scenes.size() == 0) return (int)ExitCode::NO_SCENES;
        
        PS_CORE_DEBUG("Running application");
        engine->getWindow()->resize(1280, 720);
        while (engine->getWindow()->isOpen())
        {
            if (scenes[0]->getState() == pcs::SceneState::FINISHED)
            {
                std::vector<Scene*> temp;

                for (int i = 1; i < scenes.size(); i++)
                    temp.push_back(scenes[i]);

                if (temp.size() == 0) break;
                scenes = temp;
            }

            engine->renderScene(scenes[0]);
        }

        // while window is open
        //   if state of scene is finished,
        //     remove first item of scenes and move all items up
        //   else if error 
        //     exit program
        //
        //   render the scene

        return (int)ExitCode::END_OF_PROGRAM;
    }
}