#include "Perceus/Core/Graphics/RawModel.h"

#include "Perceus/Data/Matrix.h"

#include <iostream>

namespace pcs
{
    RawModel::RawModel(const VertexArray &vertex)
    {
        loadVertices(vertex.getVertices());
        loadNormals(vertex.getNormals());
        loadTexCoords(vertex.getTexCoords());
        loadColors(vertex.getColors());
        loadTangents(vertex.getTangents());
        loadBitangents(vertex.getBitangents());
    }

    RawModel::~RawModel()
    {
        PS_CORE_DEBUG("Destroying RawModel");
        
        for (int i = 0; i < (int)TextureTypes::Count; i++)
        {
            Texture* tex = textures.textures[i];
            if (tex)
                textures.textures[i]->destroy();
        }
    }

    bool RawModel::loadColors(std::vector<Color> colors)
    {
        PS_CORE_DEBUG("Binding {0} color(s)", colors.size());
        bindBuffer(rend::BufferIndex::Color, 4, colors);
        return true;
    }

    bool RawModel::loadNormals(std::vector<Vec3f> normals)
    {
        PS_CORE_DEBUG("Binding {0} normal(s)", normals.size());
        bindBuffer(rend::BufferIndex::Normal, 3, normals);
        return true;
    }

    bool RawModel::loadVertices(std::vector<Vec3f> vertices)
    {
        PS_CORE_DEBUG("Binding {0} vertice(s)", vertices.size());
        bindBuffer(rend::BufferIndex::Vertices, 3, vertices);
        return true;
    }
    
    bool RawModel::loadTexCoords(std::vector<Vec2f> texCoords)
    {
        PS_CORE_DEBUG("Binding {0} texture coordinate(s)", texCoords.size());
        bindBuffer(rend::BufferIndex::TexCoords, 2, texCoords);
        return true;
    }

    bool RawModel::loadModelMatrices(std::vector<Mat4f> &matrices)
    {
        PS_CORE_DEBUG("Binding {0} model matrice(s)", matrices.size());
        bindBuffer(matrices);
        return true;
    }

    bool RawModel::loadBitangents(std::vector<Vec3f> bitangents)
    {
        //bindBuffer(rend::BufferIndex::Bitangents, 3, bitangents);
        return true;
    }

    bool RawModel::loadTangents(std::vector<Vec3f> tangents)
    {
        PS_CORE_DEBUG("Binding {0} tangent(s)", tangents.size());
        bindBuffer(rend::BufferIndex::Tangents, 3, tangents);
        return true;
    }

    bool RawModel::generateIndices(std::vector<Vec3f> vertices)
    {
        PS_CORE_DEBUG("Generating indices");
        std::vector<unsigned int> indices(vertices.size());

        for (int i = 0; i < vertices.size(); i++)
            indices[i] = i;

        bindBuffer(rend::BufferIndex::Indices, 1, indices);
        return true;
    }
}