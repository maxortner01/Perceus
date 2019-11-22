#include "Perceus/Core/Graphics/Entities/VertexArray.h"

#include "Perceus/Data/Triangle.h"

#include <iostream>

namespace pcs
{

#define getType(type, name)\
        std::vector<type> v;\
        v.reserve(vertices.size());\
        for (int i = 0; i < vertices.size(); i++)\
            v.push_back(vertices[i].name);\
        return v;

    std::vector<Color> VertexArray::getColors() const
    {
        getType(Color, color);
    }

    std::vector<Vec3f> VertexArray::getNormals()  const
    {
        std::vector<Vec3f> v;
        v.reserve(vertices.size());
        for (int i = 0; i < vertices.size(); i++)
            if (vertices[i].normal != Vec3f(0, 0, 0))
                v.push_back(vertices[i].normal);

        return v;
    }

    std::vector<Vec3f> VertexArray::getVertices() const
    {
        getType(Vec3f, vertex);
    } 

    std::vector<Vec2f> VertexArray::getTexCoords() const
    {
        getType(Vec2f, tex);
    }

    std::vector<Vec3f> VertexArray::getTangents() const
    {
        getType(Vec3f, tangent);
    }

    void VertexArray::calculateNormals(bool smooth_shading)
    {
        for (int i = 0; i < indices.size() / 3; i++)
        {
            Triangle tri(
                vertices[ indices[i * 3 + 0] ].vertex,
                vertices[ indices[i * 3 + 1] ].vertex,
                vertices[ indices[i * 3 + 2] ].vertex
            );

            for (int j = 0; j < 3; j++)
            {                
                if (!smooth_shading)
                    vertices[ indices[i * 3 + j] ].normal += tri.getNormal();
                else
                    vertices[ indices[i * 3 + j] ].normal = tri.getNormal();
            }
        }

        for (int i = 0; i < vertices.size(); i++)
            vertices[i].normal = normalize(vertices[i].normal);
    }
}