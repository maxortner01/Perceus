#include "Perceus/Core/Graphics/ForwardRenderer.h"

namespace pcs
{
    int ForwardRenderer::render(RawModel* rawModel, unsigned int count) const
    {
        rend::Buffer* vertexBuff = &rawModel->getBuffer(rend::BufferIndex::Indices);

        vertexBuff->bind();
        //PS_CORE_DEBUG(" -- {0} --", rawModel->getBuffer(rend::BufferIndex::Vertices).getCount());

        rendAPI()->renderInstanced(vertexBuff->getCount(), count);

        vertexBuff->unbind();

        return (int)RenderFlag::GOOD;
    }

    int ForwardRenderer::render(std::vector<Model*> models) const
    {
        RawModel* rawModel = models.at(0)->getRawModel();

        double before_time = rendAPI()->getTime();

        std::vector<Vec3f> translations;
        processModels(models, { &translations });
        //translations.resize(models.size());
        //for (int i = 0; i < models.size(); i++)
        //{
        //    models[i]->update();
        //    translations[i] = models[i]->getLocation();
        //}

        rawModel->loadTranslations(translations);

        double elapsed_time = rendAPI()->getTime() - before_time;
        getProcessTime() = elapsed_time;

        return render(rawModel, models.size());
    }
}