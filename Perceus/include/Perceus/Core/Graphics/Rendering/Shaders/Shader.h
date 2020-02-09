#pragma once

#include "Perceus/Data/ObjectID.h"
#include "Perceus/Data/Status.h"
#include "../RenderObject.h"

#include "Perceus/Data/Inc.h"

#include <unordered_map>
#include <string>

namespace pcs
{
    enum class ShaderStatus
    {
        CompileFailed,
        CompileSucceeded,
        FileDoesNotExist
    };

    enum class ShaderType
    {
        Vertex,
        Fragment,
        Count
    };

    class Shader : 
        public rend::RenderObject, public Data::ObjectID<Shader>, public Data::Status<ShaderStatus>
    {
        ShaderType type;

    public:
        PERC_API Shader(ShaderType t);
        PERC_API ~Shader();

        PERC_API int loadFromFile(std::string filename);
        PERC_API int loadFromString(const std::string &str);

        ShaderType getType() const { return type; }
    };
}