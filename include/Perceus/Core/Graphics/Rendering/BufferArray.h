#pragma once

#include "Buffer.h"

#define ARRAY_SIZE 16

namespace pcs
{
namespace rend
{
    enum class BufferIndex
    {
        Vertices
    };

    class BufferArray : public RenderObject
    {
        unsigned int id;
        std::vector<Buffer*> buffers;

    protected:
        template<typename T>
        void bindBuffer(BufferIndex buffer, unsigned int members, std::vector<T> data)
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

    public:
        BufferArray();
        ~BufferArray();

        Buffer &getBuffer(BufferIndex buffer) { return *buffers[(int)buffer]; }
        unsigned int &getID() { return id; }
    };
}
}