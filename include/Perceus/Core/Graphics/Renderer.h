#pragma once

#include "Perceus/Data/Singleton.h"
#include "Rendering/RenderObject.h"
#include "RawModel.h"

namespace pcs
{
    enum class RenderFlag
    {
        GOOD,
        ERROR
    };

    class Renderer : public rend::RenderObject
    {
    public:
        virtual int render(RawModel* rawModel) const = 0;
    };
}