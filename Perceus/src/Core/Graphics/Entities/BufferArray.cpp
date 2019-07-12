#include "Perceus/Core/Graphics/Entities/BufferArray.h"

namespace pcs
{
namespace rend
{
    BufferArray::BufferArray()
    {
        rendAPI()->makeBufferArray(this);
        buffers.resize(ARRAY_SIZE);
    };

    BufferArray::~BufferArray()
    {
        PS_CORE_DEBUG("Destroying BufferArray");
        rendAPI()->destroyBufferArray(this);

        for (int i = 0; i < buffers.size(); i++)
            if (buffers[i]) delete buffers[i];

        PS_CORE_DEBUG("Buffer Array Destroyed");
    }
}
}