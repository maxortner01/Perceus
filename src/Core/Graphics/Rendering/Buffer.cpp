#include "Perceus/Core/Graphics/Rendering/Buffer.h"

namespace pcs
{
namespace rend
{
    Buffer::Buffer(unsigned int index) :
        _index(index)
    {
        rendAPI()->makeBuffer(this);

        PS_CORE_DEBUG("Vertex Buffer ({0}) created", getID());
    }

    Buffer::~Buffer()
    {
        rendAPI()->destroyBuffer(this);

        PS_CORE_DEBUG("Vertex Buffer ({0}) destroyed", getID());
    }
}
}