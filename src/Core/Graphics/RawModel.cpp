#include "Perceus/Core/Graphics/RawModel.h"

#include "Perceus/Data/Matrix.h"

namespace pcs
{
    bool RawModel::loadVertices(std::vector<Vec3f> vertices)
    {
        bindBuffer(rend::BufferIndex::Vertices, 3, vertices);
        return true;
    }

    bool RawModel::loadModelMatrices(std::vector<Mat4f> &matrices)
    {
        bindBuffer(matrices);
        return true;
    }

    bool RawModel::generateIndices(std::vector<Vec3f> vertices)
    {
        std::vector<unsigned int> indices(vertices.size());

        for (int i = 0; i < vertices.size(); i++)
            indices[i] = i;

        bindBuffer(rend::BufferIndex::Indices, 1, indices);
        return true;
    }
}