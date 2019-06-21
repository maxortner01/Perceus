#pragma once

#include "Perceus/Data/Singleton.h"
#include "Rendering/RenderObject.h"
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

        bool processModels(std::vector<Model*> &models, std::vector<Mat4f> &matrices) const;

    public:
        virtual int render(RawModel* rawModel, unsigned int count = 1) const = 0;
        virtual int render(std::vector<Model*> models) const = 0;

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