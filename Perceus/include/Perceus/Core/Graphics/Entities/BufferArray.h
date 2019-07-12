#pragma once

#include "Perceus/Data/Matrix.h"
#include "Buffer.h"

#define ARRAY_SIZE 16

namespace pcs
{
namespace rend
{
    class BufferArray : 
        public RenderObject, public Data::ObjectID<BufferArray>
    {
        std::vector<Buffer*> buffers;

    protected:
        template<typename T>
        void bindBuffer(BufferIndex buffer, unsigned int members, std::vector<T> &data)
        {
            if (!buffers.at((int)buffer)) 
            {
                buffers.at((int)buffer) = new Buffer((int)buffer, data, members);
            }
            else
            {
                buffers.at((int)buffer)->bindData(data, members);
            }
        }
        
        
        void bindBuffer(std::vector<Mat4f> &data)
        {
            unsigned int index = (int)BufferIndex::ModelMatrix;
            if (!buffers.at((index))) 
            {
                buffers.at(index) = new Buffer(index, data);
            }
            else
            {
                buffers.at(index)->bindData(data);
            }
        }

    public:
        BufferArray();
        virtual ~BufferArray();

        Buffer &getBuffer(BufferIndex buffer) { return *buffers[(int)buffer]; }

        void bind() const   { rendAPI()->bindBufferArray(id); }
        void unbind() const { rendAPI()->bindBufferArray(0);  }

        static const char* getBufferName(unsigned int index)
        {
            return (const char *[]) {
                "Vertices",
                "Normal",
                "TexCoords",
                "Color",
                "Tangents",
                "ModelMatrix",
                "Indices"
            }[index];
        }
    };
}
}