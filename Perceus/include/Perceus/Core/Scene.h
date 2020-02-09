#pragma once

<<<<<<< HEAD
#include "Graphics/Entities/Camera.h"
#include "Perceus/Data/Status.h"
#include "Graphics/Rendering/RenderObject.h"
=======
#include "Perceus/Data/Inc.h"

#include "Graphics/Entities/Camera.h"
#include "Perceus/Data/Status.h"
#include "Graphics/Rendering/RenderObject.h"
#include "Graphics/Entities/Model.h"
#include "Graphics/Rendering/Shaders/ShaderProgram.h"
>>>>>>> master

namespace pcs
{
    class Application;

    // State flags for scenes
    enum class SceneState {
        Running,
        Error,
        Finished,
        None
    };

<<<<<<< HEAD
    // Category for each context of rendering
    class Scene : 
        public Data::Status<SceneState>,
        public rend::RenderObject
    {   
        friend class Engine;
        Camera camera;
=======
    /**
     * @brief Class that represents a context of rendering.
     */
    class PERC_API Scene : public Data::Status<SceneState>, public rend::RenderObject
    {   
        friend class Engine;

        Camera*       camera;
        Application*  current_application;
        ShaderProgram* program;
        std::vector<Model*> models;

        // Holds current frame
        unsigned int frame;
>>>>>>> master

        // Render and handle states
        void _render();

    protected:
<<<<<<< HEAD
        bool pollEvent(Event** event);
=======
		bool pollEvent(Event*& event);

        template<typename T = pcs::Model, typename... Args>
        Model* makeModel(Args... args)
        {
            models.push_back(new T(args...));
            return models.at(models.size() - 1);
        }

        template<typename T = pcs::Model>
        T& getLastModel() { return *(T*)models.at(models.size() - 1); }

        void setShaderProgram(ShaderProgram* prog)
        {
			if (program) delete program;

            program = prog;
        }
>>>>>>> master

        virtual void render() = 0;

    public:
<<<<<<< HEAD
        Scene(float FOV = 90.f);
        virtual ~Scene();

        Camera& getCamera() { return camera; }
=======
        /**
         * @brief Constructs a new Scene object
         * 
         * @param FOV Field of View in which to make the camera
         * @param size The default pre-allocation size for storing models
         */
        Scene(Application* app, float FOV = 90.f, const unsigned int size = 256);
        virtual ~Scene();

        /**
         * @brief Toggles the visibility of the camera. 
         * @param visible Whether or not the cursor should be visible.
         */
        void toggleCursor(bool visible) const;

        /**
         * @brief Get the current frame count.
         * @return unsigned int current frame count
         */
        unsigned int getFrameCount() const { return frame; }

        /**
         * @brief Get the camera for this scene
         * @return Camera& Current camera
         */
        Camera& getCamera() const { return *camera; }

        ShaderProgram& getShaderProgram() const { return *program; }

        /**
         * @brief Get the Application object associated with this scene
         * @return Application& Current application
         */
        Application& getApplication() const;
>>>>>>> master
    };
}