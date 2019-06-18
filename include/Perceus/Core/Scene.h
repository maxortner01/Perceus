#pragma once

#include "Graphics/Rendering/Events.h"

namespace pcs
{
    // State flags for scenes
    enum {
        RUNNING,
        ERROR,
        FINISHED,
        NONE
    } typedef SceneState;

    // Category for each context of rendering
    class Scene
    {   
        friend class Engine;
        // Current state of the scene
        SceneState state;

        // Render and handle states
        void _render();

    protected:
        // Change the state of the scene
        bool setState(SceneState s);

        bool pollEvent(Event** event);

        virtual void render() = 0;

    public:
        Scene();
        virtual ~Scene();

        // Get the current state of the scene
        SceneState getState() const;
    };
}