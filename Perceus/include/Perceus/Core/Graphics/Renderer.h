#pragma once

#include "Perceus/Core/Graphics/Rendering/Shaders/ShaderProgram.h"
#include "Perceus/Data/Singleton.h"
#include "Rendering/RenderObject.h"

#include "Camera.h"
#include "Model.h"

namespace pcs
{
    enum class RenderFlag
    {
        GOOD,
        ERROR
    };

    class Renderer : public rend::RenderObject
    {
    protected:
        double processModels(RawModel* rawModel, std::vector<Model*> &models) const;

    public:
        virtual int render(RawModel* rawModel, ShaderProgram* shader, Camera* camera, unsigned int count = 1) const = 0;
        int render(std::vector<Model*> models, ShaderProgram* shader, Camera* camera) const;

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