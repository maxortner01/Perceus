#pragma once

#include "../File.h"
#include "Perceus/Core/Graphics/VertexArray.h"

namespace pcs
{
namespace Util
{
    class RawModelParser : public File
    {
    public:
        using File::File;

        virtual VertexArray* parseFile() const = 0;
    };
}
}