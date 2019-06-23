#pragma once

#include <vector>
#include "Vertex.h"

namespace pcs
{
    class VertexArray
    {
        std::vector<Vertex> vertices;

    public:
        Vertex &getVertex(const int index) { return vertices[index]; }
        void pushVertex(Vertex vertex)     { vertices.push_back(vertex); }

        std::vector<Vec3f> getVertices() const;
    };
}