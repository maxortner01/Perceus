#pragma once

#include "Perceus/Data/Vector.h"
#include "Rendering/BufferArray.h"

namespace pcs
{
    class RawModel : public rend::BufferArray
    {
    public:
        bool loadVertices(std::vector<Vec3f> vertices);
        bool loadTranslations(std::vector<Vec3f> translations);

        bool generateIndices(std::vector<Vec3f> vertices);
    };
}