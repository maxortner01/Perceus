#pragma once

#include "Perceus/Data/Vector.h"
#include "Rendering/BufferArray.h"

namespace pcs
{
    class RawModel : public rend::BufferArray
    {
    public:
        bool loadVertices(std::vector<float> vertices);
    };
}