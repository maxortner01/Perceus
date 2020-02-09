#include "Perceus/Core/Graphics/Entities/BufferArray.h"

namespace pcs
{
namespace rend
{
    BufferArray::BufferArray()
    {
        rendAPI()->makeBufferArray(this);
<<<<<<< HEAD
        buffers.resize(ARRAY_SIZE);
=======

        unsigned int count = (unsigned int)BufferIndex::BufferCount;
        buffers = (Buffer**)std::calloc(count, sizeof(void*));
>>>>>>> master
    };

    BufferArray::~BufferArray()
    {
        PS_CORE_DEBUG("Destroying BufferArray");
        rendAPI()->destroyBufferArray(this);

<<<<<<< HEAD
        for (int i = 0; i < buffers.size(); i++)
            if (buffers[i]) delete buffers[i];

=======
        for (int i = 0; i < (int)BufferIndex::BufferCount; i++)
            if (buffers + i) delete *(buffers + i);

        std::free(buffers);
>>>>>>> master
        PS_CORE_DEBUG("Buffer Array Destroyed");
    }
}
}