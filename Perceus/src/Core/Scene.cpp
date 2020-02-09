#include "Perceus/Core/Scene.h"

#include "Perceus/Core/Graphics/Rendering/Events/EventHandler.h"

#include "Perceus/Core/Application.h"

#include <iostream>

#include "Perceus/Util/Memory/RegTable.h"

namespace pcs
{
    using namespace Util::Mem;

    void Scene::_render()
    {
        setStatus(SceneState::Running);
        render();
        frame++;
    }

<<<<<<< HEAD
    bool Scene::pollEvent(Event** event)
=======
    bool Scene::pollEvent(Event*& event)
>>>>>>> master
    {
        Event* e = EventHandler::get().getEvent();

        if (e == nullptr) return false;
        
<<<<<<< HEAD
        *event = e;
        return true;
    }

    Scene::Scene(float FOV) : 
        Data::Status<SceneState>(SceneState::None),
        camera( FOV )
=======
        event = e;
        return true;
    }

    Scene::Scene(Application* app, float FOV, const unsigned int size) : 
        Data::Status<SceneState>(SceneState::None),
        current_application(app), 
        frame(0)
>>>>>>> master
    {
        PS_CORE_DEBUG("Constructing Scene");

        getValues() = {
            "Running",
            "Error",
            "Finished",
            "None"
        };
<<<<<<< HEAD
=======

        camera = new Camera( &app->getCurrentWindow(), FOV );
        models.reserve(size);
>>>>>>> master
    }

    Scene::~Scene()
    {
        for (int i = 0; i < models.size(); i++)
            if (models[i]) delete models[i];

        delete camera;
    }

    void Scene::toggleCursor(bool visible) const
    {
        rendAPI()->toggleCursor(Window::get(0), visible);
    }
<<<<<<< HEAD
=======

    Application& Scene::getApplication() const
    {
        return *current_application;
    }
>>>>>>> master
}