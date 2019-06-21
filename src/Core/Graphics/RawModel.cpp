#include "Perceus/Core/Graphics/RawModel.h"

namespace pcs
{
    bool RawModel::loadVertices(std::vector<Vec3f> vertices)
    {
        bindBuffer(rend::BufferIndex::Vertices, 3, vertices);
        return true;
    }

    bool RawModel::loadTranslations(std::vector<Vec3f> translations)
    {
        bindBuffer(rend::BufferIndex::Translation, 3, translations);
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