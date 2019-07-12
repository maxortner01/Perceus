#include "Perceus/Core/Scene.h"

#include "Perceus/Core/Graphics/Rendering/Events/EventHandler.h"

#include <iostream>

#include "Perceus/Util/Memory/RegTable.h"

namespace pcs
{
    using namespace Util::Mem;

    void Scene::_render()
    {
        setStatus(SceneState::Running);
        render();
    }

    bool Scene::pollEvent(Event** event)
    {
        Event* e = EventHandler::get().getEvent();

        if (e == nullptr) return false;
        
        *event = e;
        return true;
    }

    Scene::Scene(float FOV) : 
        Data::Status<SceneState>(SceneState::None),
        camera( FOV )
    {
        PS_CORE_DEBUG("Constructing Scene");

        getValues() = {
            "Running",
            "Error",
            "Finished",
            "None"
        };
    }

    Scene::~Scene()
    {

    }
}