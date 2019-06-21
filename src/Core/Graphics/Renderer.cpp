#include "Perceus/Core/Graphics/Renderer.h"

#include <iostream>
#include <thread>

namespace pcs
{
    void processModel(std::vector<Model*> models, std::vector<Vec3f>* output)
    {
        output->resize(models.size());
        for (int i = 0; i < models.size(); i++)
        {
            //std::cout << i << "  " << models.size() << std::endl;
            models.at(i)->update();
            output->at(i) = models[i]->getLocation();
        }
    }

    bool Renderer::processModels(std::vector<Model*> &models, rend::TInfo info) const
    {
        const unsigned int per_thread_count = 81000;

        std::vector<std::thread*> threads;
        std::vector<std::vector<Vec3f>*> translations; 

        unsigned int thread_counter = 0;
        unsigned int last_pos = 0;
        info.translation->reserve(models.size());
        for (int i = 0; i < models.size(); i++)
        {
            if (thread_counter == per_thread_count)
            {
                translations.push_back(new std::vector<Vec3f>());
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
                info.translation->push_back(models[i]->getLocation());
            }

            thread_counter++;
        }

        getThreadCount() = threads.size();

        for (int i = 0; i < threads.size(); i++)
        {
            threads[i]->join();
            info.translation->insert(info.translation->begin(), translations[i]->begin(), translations[i]->end());
            delete threads[i];
            delete translations[i];
        }

        return true;
    }
}