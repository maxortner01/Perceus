#include "Perceus/Core/Graphics/Entities/RawModel.h"

#include "Perceus/Data/Matrix.h"

<<<<<<< HEAD
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
=======
namespace pcs
{
    std::vector<RawModel*> RawModel::rawModels;

    void RawModel::flushRawModels()
    {
        int size = rawModels.size();
        for (int i = 0; i < size; i++)
            delete rawModels[i];

		rawModels.clear();
    }

    RawModel::RawModel(VertexArray& vertex)
    {
        if (vertex.getIndices().size() == 0)
            generateIndices(vertex);

        else if (vertex.getIndices().size() < vertex.getVertices().size())
            generateIndices(vertex, vertex.getIndices().size());

        else
            loadIndices(vertex.getIndices());

        loadVertices(vertex.getVertices());
        loadTexCoords(vertex.getTexCoords());
        loadColors(vertex.getColors());
        loadTangents(vertex.getTangents());

        if (vertex.getNormals().size() == 0)
            vertex.calculateNormals();

        loadNormals(vertex.getNormals());
    }
    
    bool RawModel::generateIndices(VertexArray& vertices, const int start_index)
    {
        PS_CORE_DEBUG("Generating indices");
        std::vector<unsigned int> indices(vertices.getVertices().size());

        for (int i = start_index; i < vertices.getVertices().size(); i++)
            indices[i] = i;

        vertices.getIndices() = indices;
        loadIndices(indices);
        return true;
    }

    RawModel* RawModel::Create(VertexArray& vertex)
    {
        rawModels.push_back(new RawModel(vertex));
		RawModel* r = rawModels[rawModels.size() - 1];

		r->getID() = rawModels.size() - 1;
		
		return r;
>>>>>>> master
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

<<<<<<< HEAD
    bool RawModel::loadColors(std::vector<Color> colors)
=======
    bool RawModel::loadColors(const std::vector<Color>& colors)
>>>>>>> master
    {
        PS_CORE_DEBUG("Binding {0} color(s)", colors.size());
        bindBuffer(rend::BufferIndex::Color, 4, colors);
        return true;
    }

<<<<<<< HEAD
    bool RawModel::loadNormals(std::vector<Vec3f> normals)
=======
    bool RawModel::loadNormals(const std::vector<Vec3f>& normals)
>>>>>>> master
    {
        PS_CORE_DEBUG("Binding {0} normal(s)", normals.size());
        bindBuffer(rend::BufferIndex::Normal, 3, normals);
        return true;
    }

<<<<<<< HEAD
    bool RawModel::loadVertices(std::vector<Vec3f> vertices)
=======
    bool RawModel::loadVertices(const std::vector<Vec3f>& vertices)
>>>>>>> master
    {
        PS_CORE_DEBUG("Binding {0} vertice(s)", vertices.size());
        bindBuffer(rend::BufferIndex::Vertices, 3, vertices);
        return true;
    }
    
<<<<<<< HEAD
    bool RawModel::loadTexCoords(std::vector<Vec2f> texCoords)
=======
    bool RawModel::loadTexCoords(const std::vector<Vec2f>& texCoords)
>>>>>>> master
    {
        PS_CORE_DEBUG("Binding {0} texture coordinate(s)", texCoords.size());
        bindBuffer(rend::BufferIndex::TexCoords, 2, texCoords);
        return true;
    }

<<<<<<< HEAD
    bool RawModel::loadModelMatrices(std::vector<Mat4f> &matrices)
=======
    bool RawModel::loadModelMatrices(const std::vector<Mat4f>& matrices)
>>>>>>> master
    {
        PS_CORE_DEBUG("Binding {0} model matrice(s)", matrices.size());
        bindBuffer(matrices);
        return true;
    }

<<<<<<< HEAD
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
=======
    bool RawModel::loadTangents(const std::vector<Vec3f>& tangents)
    {
        PS_CORE_DEBUG("Binding {0} tangent(s)", tangents.size());
        bindBuffer(rend::BufferIndex::Tangents, 3, tangents);
        return true;
    }

    bool RawModel::loadIndices(const std::vector<unsigned int>& indices)
    {
        PS_CORE_DEBUG("Binding {0} indices", indices.size());
        bindBuffer(rend::BufferIndex::Indices, 1, indices);
        return true;
    }
    
    void RawModel::setColor(const Color& color)
    {
        const unsigned int vertex_count = getBuffer(rend::BufferIndex::Vertices).getCount();
        if (vertex_count == 0) return;

        std::vector<Color> colors; colors.reserve(vertex_count);

        for (int i = 0; i < vertex_count; i++)
            colors.push_back(color);

        loadColors(colors);
    }
}
>>>>>>> master
