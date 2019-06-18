#include "Perceus/Core/Scene.h"

#include "Perceus/Core/Graphics/Rendering/Events/EventHandler.h"

#include <iostream>

namespace pcs
{
    void Scene::_render()
    {
        state = RUNNING;
        render();
    }

    bool Scene::setState(SceneState s)
    {
        state = s;
        return true;
    }

    bool Scene::pollEvent(Event** event)
    {
        Event* e = EventHandler::get().getEvent();

        if (e == nullptr) return false;
        

        *event = e;
        return true;
    }

    Scene::Scene() : state(NONE)
    {

    }

    Scene::~Scene()
    {

    }

    SceneState Scene::getState() const
    {
        return state;
    }
}