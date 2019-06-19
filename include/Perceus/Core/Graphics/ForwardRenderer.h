#pragma once

#include "Renderer.h"

namespace pcs
{
    class ForwardRenderer : public Renderer, public Data::Singleton<ForwardRenderer>
    {
    public:
        int render(RawModel* rawModel) const;
    };
}