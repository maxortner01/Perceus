#pragma once

#include "Perceus/Data/Color.h"
#include "Perceus/Data/Vector.h"
#include "../Entities/BufferArray.h"

#include "../Texture.h"
#include "../Entities/VertexArray.h"

<<<<<<< HEAD
=======
#include "Perceus/Data/Inc.h"

>>>>>>> master
namespace pcs
{
    class RawModel : public rend::BufferArray
    {
<<<<<<< HEAD
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
=======
        friend class Engine;

        TextureArray textures;
        static std::vector<RawModel*> rawModels;

        static void flushRawModels();

        RawModel(VertexArray& vertex);

        bool generateIndices(VertexArray& vertices, const int start_index = 0);

    public:
        static RawModel PERC_API * Create(VertexArray& vertex);

        PERC_API ~RawModel();

        TextureArray& getTextures() { return textures; }

        bool PERC_API loadColors(const std::vector<Color>& colors);
        bool PERC_API loadNormals(const std::vector<Vec3f>& normals);
        bool PERC_API loadVertices(const std::vector<Vec3f>& vertices);
        bool PERC_API loadTexCoords(const std::vector<Vec2f>& texCoords);
        bool PERC_API loadModelMatrices(const std::vector<Mat4f>& matrices);
        bool PERC_API loadTangents(const std::vector<Vec3f>& tangents);

        bool PERC_API loadIndices(const std::vector<unsigned int> &indices);

        void PERC_API setColor(const Color& color);
    };
}
>>>>>>> master
