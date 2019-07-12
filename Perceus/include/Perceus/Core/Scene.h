#pragma once

#include "Graphics/Entities/Camera.h"
#include "Perceus/Data/Status.h"
#include "Graphics/Rendering/RenderObject.h"

namespace pcs
{
    // State flags for scenes
    enum class SceneState {
        Running,
        Error,
        Finished,
        None
    };

    // Category for each context of rendering
    class Scene : 
        public Data::Status<SceneState>,
        public rend::RenderObject
    {   
        friend class Engine;
        Camera camera;

        // Render and handle states
        void _render();

    protected:
        bool pollEvent(Event** event);

        virtual void render() = 0;

    public:
        Scene(float FOV = 90.f);
        virtual ~Scene();

        Camera& getCamera() { return camera; }
    };
}