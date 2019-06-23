#include "Perceus/Core/Graphics/VertexArray.h"

namespace pcs
{
    std::vector<Vec3f> VertexArray::getVertices() const
    {
        std::vector<Vec3f> v = std::vector<Vec3f>();
        v.reserve(vertices.size());

        for (int i = 0; i < vertices.size(); i++)
            v.push_back(vertices[i].vertex);

        return v;
    }
}