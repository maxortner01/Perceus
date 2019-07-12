#include "Perceus/Core/Graphics/Rendering/Shaders/Shader.h"

namespace pcs
{
    Shader::Shader(ShaderType t) :
        type(t)
    {
        getValues() = {
            "Vertex",
            "Fragment"
        };

        rendAPI()->makeShader(this);
    }

    Shader::~Shader()
    {
        rendAPI()->destroyShader(this);
    }

    int Shader::loadShaderFromString(std::string str)
    {
        const char* s = str.c_str();
        return rendAPI()->compileShader(this, s);
    }
} 
