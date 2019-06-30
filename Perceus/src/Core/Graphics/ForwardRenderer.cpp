#include "Perceus/Core/Graphics/ForwardRenderer.h"

#include <iostream>

namespace pcs
{
    int ForwardRenderer::render(RawModel* rawModel, ShaderProgram* shader, Camera* camera, unsigned int count) const
    {
        //static Texture* texture;
        
        //if (!texture)
        //{
        //    texture = new Texture("Client/res/Sword1/color.png");
        //}

        rend::Buffer* vertexBuff = &rawModel->getBuffer(rend::BufferIndex::Indices);

        vertexBuff->bind();
        //PS_CORE_DEBUG(" -- {0} --", rawModel->getBuffer(rend::BufferIndex::Vertices).getCount());

        const char* textures[] = {
            "albedo", "normal", "roughness"
        };
        
        for (int i = 0; i < (int)TextureTypes::Count; i++)
        {
            Texture* tex = rawModel->getTextures().textures[i];

            if (tex)
            {
                tex->bind(i);
                shader->setUniform(textures[i], i);
            }
        }

        shader->use();

        shader->setUniform("camera_position", camera->getLocation());
        shader->setUniform("projection", camera->getProjection());
        shader->setUniform("view",       camera->getView()); 

        rendAPI()->renderInstanced(vertexBuff->getCount(), count);

        shader->close();

        vertexBuff->unbind();

        return (int)RenderFlag::GOOD;
    }
}