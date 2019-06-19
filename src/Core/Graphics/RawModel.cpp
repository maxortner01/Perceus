#include "Perceus/Core/Graphics/RawModel.h"

namespace pcs
{
    bool RawModel::loadVertices(std::vector<Vec3f> vertices)
    {
        bindBuffer(rend::BufferIndex::Vertices, 3, vertices);
        return true;
    }
}