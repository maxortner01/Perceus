#pragma once

#include <vector>
#include "Perceus/Data/Vertex.h"

namespace pcs
{
    class VertexArray
    {
        std::vector<Vertex> vertices;

    public:
        std::vector<Vertex> &getVertexArray() { return vertices; }
        Vertex &getVertex(const int index) { return vertices[index]; }
        void pushVertex(Vertex vertex)     { vertices.push_back(vertex); }
 
        std::vector<Color> getColors()     const;
        std::vector<Vec3f> getNormals()    const;
        std::vector<Vec3f> getVertices()   const; 
        std::vector<Vec2f> getTexCoords()  const;
        std::vector<Vec3f> getBitangents() const;
        std::vector<Vec3f> getTangents()   const;
    };

}