#include "Perceus/Core/Graphics/Entities/Primitives/Primitive.h"

namespace pcs
{
    template<typename _PRIM_TYPE>
    Primitive<_PRIM_TYPE>::Primitive() :
        pcs::Model(_PRIM_TYPE::getRawModel())
    {

    }

    void PlaneType::genRawModel(RawModel*& rawModel)
    {
        VertexArray array;
        Vertex vert;
        vert.color = Color(255, 255, 255, 255);

        // Closest, bottom left  0
        vert.vertex = Vec3f(-1, 0,  1);
        array.pushVertex(vert);
        
        // Furthest, bottom left  1
        vert.vertex = Vec3f(-1, 0, -1);
        array.pushVertex(vert);

        // Furthest, bottom right  2
        vert.vertex = Vec3f( 1, 0, -1);
        array.pushVertex(vert);
        
        // Closest, bottom right  3
        vert.vertex = Vec3f( 1, 0,  1);
        array.pushVertex(vert);

        array.getIndices() = {
            0, 1, 2,
            2, 3, 0
        };

        rawModel = RawModel::Create(array);
    }

    void SphereType::genRawModel(RawModel*& rawModel)
    {

    }

    void CubeType::genRawModel(RawModel*& rawModel)
    {
        VertexArray array;
        Vec3f verts[] = {
            Vec3f(-1, -1,  1), Vec3f(-1, -1, -1), 
            Vec3f( 1, -1, -1), Vec3f( 1, -1,  1),
            Vec3f(-1,  1,  1), Vec3f(-1,  1, -1),
            Vec3f( 1,  1, -1), Vec3f( 1,  1,  1)
        };

        std::vector<unsigned int> indices = {
            // Bottom
            0, 1, 2,
            0, 3, 2,

            // Top
            4, 5, 6,
            4, 7, 6,

            // Left
            1, 5, 4,
            1, 0, 4,
            
            // Right
            2, 6, 7,
            2, 3, 7,

            // Front
            0, 4, 7,
            0, 3, 7,

            // Back
            1, 5, 6,
            1, 2, 6
        };

        for (int i = 0; i < indices.size(); i++)
        {
            Vertex vert;
            vert.color = Color(255, 255, 255, 255);

            vert.vertex = verts[indices[i]];

            array.pushVertex(vert);
        }
        
        /*
        vert.color = Color(255, 255, 255, 255);

        // Closest, bottom left  0
        vert.vertex = Vec3f(-1, -1,  1);
        array.pushVertex(vert);
        
        // Furthest, bottom left  1
        vert.vertex = Vec3f(-1, -1, -1);
        array.pushVertex(vert);

        // Furthest, bottom right  2
        vert.vertex = Vec3f( 1, -1, -1);
        array.pushVertex(vert);
        
        // Closest, bottom right  3
        vert.vertex = Vec3f( 1, -1,  1);
        array.pushVertex(vert);
        
        // Closest, top left  4
        vert.vertex = Vec3f(-1,  1,  1);
        array.pushVertex(vert);
        
        // Furthest, top left  5
        vert.vertex = Vec3f(-1,  1, -1);
        array.pushVertex(vert);

        // Furthest, top right  6
        vert.vertex = Vec3f( 1,  1, -1);
        array.pushVertex(vert);
        
        // Closest, top right  7
        vert.vertex = Vec3f( 1,  1,  1);
        array.pushVertex(vert);
        */
        

        rawModel = RawModel::Create(array);
    }

    void tempForwardDeclare()
    {
        Primitive<SphereType > Sphere;
        Primitive<CubeType   > Cube;
        Primitive<PlaneType  > Plane;
    }
}