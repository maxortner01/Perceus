#include "Perceus/Core/Graphics/ForwardRenderer.h"

namespace pcs
{
    int ForwardRenderer::render(RawModel* rawModel, ShaderProgram* shader, Camera* camera, unsigned int count) const
    {
        rend::Buffer* vertexBuff = &rawModel->getBuffer(rend::BufferIndex::Indices);

        vertexBuff->bind();
        //PS_CORE_DEBUG(" -- {0} --", rawModel->getBuffer(rend::BufferIndex::Vertices).getCount());

        shader->use();

        shader->setUniform("projection", camera->getProjection());
        shader->setUniform("view",       camera->getView());

        rendAPI()->renderInstanced(vertexBuff->getCount(), count);
        shader->close();

        vertexBuff->unbind();

        return (int)RenderFlag::GOOD;
    }
}