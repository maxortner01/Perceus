#include "Perceus/Core/Graphics/Rendering/Renderer.h"

<<<<<<< HEAD
=======
#include <iostream>
#include <thread>

>>>>>>> master
namespace pcs
{
    /*
    void processModel(std::vector<Model*> models, std::vector<Mat4f>* output)
    {
        output->resize(models.size());
        for (int i = 0; i < models.size(); i++)
        {
            models.at(i)->update();
            output->at(i) = Mat4f::makeTranslation(models[i]->getLocation());
        }
    }
    */

    /*
    bool Renderer::processModels(std::vector<Model*> &models, std::vector<Mat4f> &matrices) const
    {
        const unsigned int per_thread_count = 81000;

        std::vector<std::thread*> threads;
        std::vector<std::vector<Mat4f>*> translations; 

        unsigned int thread_counter = 0;
        unsigned int last_pos = 0;
        matrices.reserve(models.size());
        for (int i = 0; i < models.size(); i++)
        {
            if (thread_counter == per_thread_count)
            {
                translations.push_back(new std::vector<Mat4f>());
                threads.push_back(new std::thread(processModel, 
                    std::vector<Model*>(models.begin() + last_pos, models.begin() + i + 1), 
                    translations.at(translations.size() - 1)
                ));

                last_pos = i + 1;
                thread_counter = 0;
            }

            if (models.size() - last_pos < per_thread_count)
            {
                models[i]->update();
                matrices.push_back(Mat4f::makeTranslation(models[i]->getLocation()));
            }

            thread_counter++;
        }

        getThreadCount() = threads.size();

        for (int i = 0; i < threads.size(); i++)
        {
            threads[i]->join();
            matrices.insert(matrices.begin(), translations[i]->begin(), translations[i]->end());
            delete threads[i];
            delete translations[i];
        }

        return true;
    } */

    double Renderer::processModels(RawModel* rawModel, std::vector<Model*> &models) const
    {
        double before_time = rendAPI()->getTime();
        static double frame_time = 0.0;

        std::vector<Mat4f> modelMatrices;

        modelMatrices.resize(models.size());
        for (int i = 0; i < models.size(); i++)
        {
            models[i]->update(rendAPI()->getTime() - frame_time);
            modelMatrices[i] = models[i]->getModelMatrix();
        }

        frame_time = rendAPI()->getTime();

        rawModel->loadModelMatrices(modelMatrices);

        double elapsed_time = rendAPI()->getTime() - before_time;
        getProcessTime() = elapsed_time;

        return elapsed_time;
    }

<<<<<<< HEAD
    int Renderer::render(std::vector<Model*> models, ShaderProgram* shader, Camera* camera) const
    {
        RawModel* rawModel = models.at(0)->getRawModel();

        processModels(rawModel, models);

=======
    RenderFlag Renderer::render(std::vector<Model*> models, ShaderProgram* shader, Camera* camera) const
    {
        // If there are no models, exit
        if (models.size() == 0) return RenderFlag::Good;

        RawModel* rawModel = models.at(0)->getRawModel();

        // If the RawModel does not exist, exit
        if (!rawModel) return RenderFlag::NoRawModel;

        // If the RawModel doesn't contain any vertices, exit
        if (rawModel->getBuffer(rend::BufferIndex::Vertices).getCount() == 0) return RenderFlag::NoVertices;

        // Process the transformation matrices for each model
        processModels(rawModel, models);

        // Push the rawModel to the renderer
>>>>>>> master
        return render(rawModel, shader, camera, models.size());
    }
}