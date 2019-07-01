#pragma once

#include <vector>
#include "Perceus/Data/ObjectID.h"
#include "Perceus/Core/Graphics/Rendering/RenderObject.h"

namespace pcs
{
    class Texture : public Data::ObjectID, public rend::RenderObject
    {
    public:
        Texture();
        Texture(const char* location);
        ~Texture();

        void destroy();

        void bind(unsigned int layer = 0) const;
        void unbind(unsigned int layer = 0) const;

        void loadFromFile(const char* location);
    };

    enum class TextureTypes
    {
        Albedo,
        Normal,
        Count
    };

    union TextureArray
    {
        Texture* textures[(int)TextureTypes::Count];

        struct 
        {
            Texture* albedo = nullptr;
            Texture* normal = nullptr;
        };
    };
}