#include "Perceus/Core/Scene.h"

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