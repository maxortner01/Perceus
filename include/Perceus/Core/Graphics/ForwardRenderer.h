#pragma once

#include "Renderer.h"

namespace pcs
{
    class ForwardRenderer : public Renderer, public Data::Singleton<ForwardRenderer>
    {
    public:
        int render(RawModel* rawModel, unsigned int count = 1) const;
        int render(std::vector<Model*> models) const;
    };
}