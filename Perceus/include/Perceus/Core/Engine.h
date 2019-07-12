#pragma once

#include "Perceus/Data/Singleton.h"
#include "Perceus/Data/Status.h"
#include "Perceus/Core/Scene.h"

namespace pcs
{
    /**
     * @brief Enum that describes the state of a rendered frame.
     */
    enum class RenderStatus
    {
        Good,
        Failed
    };

    /**
     * @brief Handles rendering and holds the window instance.
     */
    class Engine : 
        public rend::RenderObject, public Data::Singleton<Engine>, public Data::Status<RenderStatus>
    {
        /// List of independent-typed pointers which each point to a camera
        /// associated with this engine.
        std::vector<void*> camera_directory;

        /// Window on which to render to
        Window* window;
        
    public:
        /**
         * @brief Constructs a new Engine object.
         */
        Engine();
        /**
         * @brief Destroys the Engine object.
         */
        ~Engine();

        /**
         * @brief Renders a given scene to the window.
         * 
         * @param scene Pointer to a scene to render
         * @return RenderStatus Status of the render
         */
        RenderStatus renderScene(Scene* scene) const;

        /**
         * @brief Get the Window instance associated with this engine
         * 
         * @return Window* Pointer to a window instance
         */
        Window* getWindow() { return window; }

        /**
         * @brief Push a camera to the directory
         * 
         * @param camera Camera instance to register
         */
        void pushCamera(void* camera) { camera_directory.push_back(camera); }
        /**
         * @brief Get the Camera Directory
         * 
         * @return std::vector<void*>& Camera Directory list
         */
        std::vector<void*> &getCameraDirectory() { return camera_directory; }
    };
}