#pragma once

#include "Perceus/Core/Graphics/Rendering/Shaders/ShaderProgram.h"
#include "Perceus/Data/Singleton.h"
#include "RenderObject.h"

#include "../Entities/Model.h"
#include "../Entities/Camera.h"

<<<<<<< HEAD
=======
#include "Perceus/Data/Inc.h"

>>>>>>> master
namespace pcs
{
    enum class RenderFlag
    {
        Good,
<<<<<<< HEAD
        Error
    };

    class Renderer : public rend::RenderObject
    {
    protected:
        double processModels(RawModel* rawModel, std::vector<Model*> &models) const;

    public:
        virtual int render(RawModel* rawModel, ShaderProgram* shader, Camera* camera, unsigned int count = 1) const = 0;
        int render(std::vector<Model*> models, ShaderProgram* shader, Camera* camera) const;
=======
        Error,
        NoVertices,
        NoRawModel
    };

    /**
     * @brief Interface for a class that handles every step of entity rendering.
     * 
     * By default, this class handles the seperation and distribution of the various RawModel objects
     * within a vector of Model objects and passes them to the virtual render function.
     * 
     * For an example of implementation see ForwardRenderer.
     * 
     */
    class PERC_API Renderer : public rend::RenderObject
    {
    protected:
        /**
         * @brief Calculates model matrices for each model in a given list of models.
         * 
         * @param rawModel Cooresponding RawModel object associated with each Model in the vector of models
         * @param models   Vector of Model objects to process
         * @return double  Elapsed time in seconds
         */
        double processModels(RawModel* rawModel, std::vector<Model*> &models) const;

    public:
        /**
         * @brief Pure virtual method intended for use to render a specific RawModel object a certain amount of times.
         * 
         * @param rawModel    RawModel object to render
         * @param shader      Instance of the ShaderProgram to use
         * @param camera      Camera object to render with
         * @param count       Amount of instances to render
         * @return RenderFlag Status code of the executed render
         */
        virtual RenderFlag render(RawModel* rawModel, ShaderProgram* shader, Camera* camera, unsigned int count = 1) const = 0;

        /**
         * @brief This method renders the list of models by invoking the pure virtual render function.
         * 
         * Within the process of rendering each Model, this render method will process each Model (i.e
         * calculate the transformation matrices and bind them) and send a vector of each model associated
         * with each unique RawModel to the pure virtual render method to be rendered. 
         * 
         * @param models      List of Model objects to render
         * @param shader      Instance of the ShaderProgram to use
         * @param camera      Camera object to render with
         * @return RenderFlag Status code of the executed render
         */
        RenderFlag render(std::vector<Model*> models, ShaderProgram* shader, Camera* camera) const;
>>>>>>> master

        static double &getProcessTime()
        {
            static double time;
            return time;
        }

        static unsigned int &getThreadCount() 
        {
            static unsigned int threads; 
            return threads; 
        }
    };
}