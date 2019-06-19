#include "Perceus/Core/Graphics/RawModel.h"

namespace pcs
{
    bool RawModel::loadVertices(std::vector<float> vertices)
    {
        bindBuffer(rend::BufferIndex::Vertices, 2, vertices);
        return true;
    }
}