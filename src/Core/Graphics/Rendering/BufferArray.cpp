#include "Perceus/Core/Graphics/Rendering/BufferArray.h"

#include "Perceus/Util/Log.h"

namespace pcs
{
namespace rend
{
    BufferArray::BufferArray()
    {
        rendAPI()->makeBufferArray(this);
        buffers.resize(ARRAY_SIZE);

        PS_CORE_INFO("Buffer Array ({0}) created", getID());
    };

    BufferArray::~BufferArray()
    {
        rendAPI()->destroyBufferArray(this);

        for (int i = 0; i < buffers.size(); i++)
            if (buffers[i]) delete buffers[i];

        PS_CORE_WARN("Buffer Array ({0}) destroyed", getID());
    }
}
}