#pragma once

#include "Shader.h"

namespace pcs
{
    class ShaderProgram : public rend::RenderObject, public Data::ObjectID
    {
        std::vector<Shader*> shaders;

        void destroyShaders();

    public:
        ShaderProgram();
        ~ShaderProgram();

        Shader &getShader(ShaderType type);
        bool link();

        void use()   const { rendAPI()->useProgram(id); }
        void close() const { rendAPI()->useProgram(0); }
    };
}