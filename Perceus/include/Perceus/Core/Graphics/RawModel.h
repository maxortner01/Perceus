#pragma once

#include "Perceus/Data/Color.h"
#include "Perceus/Data/Vector.h"
#include "Rendering/BufferArray.h"

#include "Texture.h"
#include "VertexArray.h"

namespace pcs
{
    class RawModel : public rend::BufferArray
    {
        TextureArray textures;

    public:
        RawModel() { }
        RawModel(const VertexArray &vertex);

        ~RawModel();

        TextureArray &getTextures() { return textures; }

        bool loadColors(std::vector<Color> colors);
        bool loadNormals(std::vector<Vec3f> normals);
        bool loadVertices(std::vector<Vec3f> vertices);
        bool loadTexCoords(std::vector<Vec2f> texCoords);
        bool loadModelMatrices(std::vector<Mat4f> &matrices);
        bool loadBitangents(std::vector<Vec3f> bitangents);
        bool loadTangents(std::vector<Vec3f> tangents);

        bool generateIndices(std::vector<Vec3f> vertices);
    };
}