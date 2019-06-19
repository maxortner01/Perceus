#include "Perceus/Core/Graphics/ForwardRenderer.h"

namespace pcs
{
    int ForwardRenderer::render(RawModel* rawModel) const
    {
        rend::Buffer* vertexBuff = &rawModel->getBuffer(rend::BufferIndex::Vertices);

        vertexBuff->bind();
        //PS_CORE_DEBUG(" -- {0} --", rawModel->getBuffer(rend::BufferIndex::Vertices).getCount());
        rendAPI()->renderArray(vertexBuff->getCount());

        vertexBuff->unbind();

        return (int)RenderFlag::GOOD;
    }
}