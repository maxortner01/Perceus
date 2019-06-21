#pragma once

#include "Buffer.h"

#define ARRAY_SIZE 16

namespace pcs
{
namespace rend
{
    class BufferArray : public RenderObject, public Data::ObjectID
    {
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

        static const char* getBufferName(unsigned int index)
        {
            return (const char *[]) {
                "Vertices",
                "Indices"
            }[index];
        }
    };
}
}