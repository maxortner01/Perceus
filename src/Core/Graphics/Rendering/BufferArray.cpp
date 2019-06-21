#include "Perceus/Core/Graphics/Rendering/BufferArray.h"

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
        rendAPI()->destroyBufferArray(this);

        for (int i = 0; i < buffers.size(); i++)
            if (buffers[i]) delete buffers[i];
    }
}
}