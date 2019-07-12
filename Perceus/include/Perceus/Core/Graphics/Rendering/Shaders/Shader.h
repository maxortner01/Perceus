#pragma once

#include "Perceus/Data/ObjectID.h"
#include "Perceus/Data/Status.h"
#include "../RenderObject.h"

#include <string>

namespace pcs
{
    enum class ShaderStatus
    {

    };

    enum class ShaderType
    {
        Vertex,
        Fragment,
        COUNT
    };

    class Shader : 
        public rend::RenderObject, public Data::ObjectID<Shader>, public Data::Status<ShaderStatus>
    {
        ShaderType type;

    public:
        Shader(ShaderType t);
        ~Shader();

        int loadShaderFromString(std::string str);

        ShaderType getType() const { return type; }
    };
}