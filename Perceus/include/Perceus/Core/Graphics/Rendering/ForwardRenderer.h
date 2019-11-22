#pragma once

#include "Renderer.h"

namespace pcs
{
    class PERC_API ForwardRenderer : public Renderer, public Data::Singleton<ForwardRenderer>
    {
    public:
        using Renderer::render;

        RenderFlag render(RawModel* rawModel, ShaderProgram* shader, Camera* camera, unsigned int count = 1) const override;
    };
}