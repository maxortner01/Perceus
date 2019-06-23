#pragma once

#include "Perceus/Data/Vector.h"
#include "Rendering/BufferArray.h"

#include "VertexArray.h"

namespace pcs
{
    class RawModel : public rend::BufferArray
    {
    public:
        RawModel() { }
        RawModel(const VertexArray &vertex);

        ~RawModel();

        bool loadVertices(std::vector<Vec3f> vertices);
        bool loadModelMatrices(std::vector<Mat4f> &matrices);

        bool generateIndices(std::vector<Vec3f> vertices);
    };
}