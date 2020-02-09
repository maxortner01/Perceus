#include "Perceus/Core/Graphics/Rendering/Shaders/Shader.h"

#include <fstream>
#include <iostream>

namespace pcs
{
    Shader::Shader(ShaderType t) :
        type(t)
    {
        getValues() = {
<<<<<<< HEAD
            "Vertex",
            "Fragment"
=======
            "Compilation Failed",
            "Compilation Succeeded",
            "File does not exist"
>>>>>>> master
        };

        rendAPI()->makeShader(this);
    }

    Shader::~Shader()
    {
        rendAPI()->destroyShader(this);
    }

    int Shader::loadFromFile(std::string filename)
    {
        std::string contents;

        std::ifstream f(filename);
        
        if (!f.good())
        {
            setStatus(ShaderStatus::FileDoesNotExist);
        }
        else
        {
            for (std::string line; std::getline(f, line);)
                contents += line + "\n";

            setStatus( (ShaderStatus)loadFromString(contents) );
        }
        
        
        return (int)getStatus();
    }

    int Shader::loadFromString(const std::string &str)
    {
        const char* s = str.c_str();
        
        setStatus( (ShaderStatus) rendAPI()->compileShader(this, s) );       

        return (int)getStatus();
    }
} 
