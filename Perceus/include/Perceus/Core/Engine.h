#pragma once

#include "Perceus/Core/Graphics/Window.h"
#include "Perceus/Data/Singleton.h"
#include "Perceus/Data/Status.h"
#include "Perceus/Core/Scene.h"

namespace pcs
{
    enum class RenderStatus
    {
        GOOD,
        FAILED
    };

    class Engine : public Data::Singleton<Engine>, public rend::RenderObject, public Data::Status<RenderStatus>
    {
        std::vector<void*> camera_directory;
        Window* window;

    public:
        Engine();
        ~Engine();

        RenderStatus renderScene(Scene* scene) const;

        Window* getWindow() { return window; }
        void pushCamera(void* camera) { camera_directory.push_back(camera); }
        std::vector<void*> &getCameraDirectory() { return camera_directory; }
    };
}