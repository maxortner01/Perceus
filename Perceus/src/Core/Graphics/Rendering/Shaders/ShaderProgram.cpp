#include "Perceus/Core/Graphics/Rendering/Shaders/ShaderProgram.h"

#include <iostream>

namespace pcs
{
    ShaderProgram::defaultShaders ShaderProgram::_shaders;

    ShaderProgram::defaultShaders::defaultShaders()
    {
        file_contents[(int)ShaderFile::Default3D] = 
            std::pair<std::string, std::string> ( 
                std::string(
                    #include "Perceus/Core/Graphics/Rendering/Shaders/ShaderFiles/default3D.vert"
                ),
                std::string(
                    #include "Perceus/Core/Graphics/Rendering/Shaders/ShaderFiles/default3D.frag"
                )
            );
    }

    ShaderProgram::defaultShaders::~defaultShaders()
    {
        for (int i = 0; i < (int)ShaderFile::Count; i++)
            delete _shaders[i];
    }

    void ShaderProgram::destroyShaders()
    {
        for (int i = 0; i < shaders.size(); i++)
            delete shaders[i];
    }

    void ShaderProgram::initializeDefaults()
    {
        //std::cout << _shaders._shaders.size() << "\n";
        if (_shaders._shaders.size() == 0)
        {
            _shaders._shaders.reserve((int)ShaderFile::Count);
            for (int i = 0; i < (int)ShaderFile::Count; i++)
            {
                ShaderProgram* p = new ShaderProgram();
                p->getShader(ShaderType::Vertex  ).loadFromString(_shaders.file_contents[i].first );
                p->getShader(ShaderType::Fragment).loadFromString(_shaders.file_contents[i].second);
                p->link();

                _shaders._shaders.push_back(p);
            }
        }
    }

    ShaderProgram::ShaderProgram()
    {
        shaders.reserve((int)ShaderType::Count);

        rendAPI()->makeProgram(this);

        for (int i = 0; i < (int)ShaderType::Count; i++)
            shaders.push_back(new Shader((ShaderType)i));
    }

    ShaderProgram::~ShaderProgram()
    {
        rendAPI()->destroyProgram(this);
    }

    Shader &ShaderProgram::getShader(ShaderType type) {
        return *shaders[(int)type];
    }

    bool ShaderProgram::link()
    {           
        if (shaders[0]->getStatus() != ShaderStatus::CompileSucceeded || shaders[1]->getStatus() != ShaderStatus::CompileSucceeded)
            return false;

        bool r = rendAPI()->linkProgram(this);

        destroyShaders();

        return r;
    }

    bool ShaderProgram::setUniform(const char* name, const Mat4f &matrix)
    {
        return rendAPI()->setUniform(this, name, matrix);
    }

    bool ShaderProgram::setUniform(const char* name, const Vec3f &var)
    {
        return rendAPI()->setUniform(this, name, var);
    }

    bool ShaderProgram::setUniform(const char* name, const int &var)
    {
        return rendAPI()->setUniform(this, name, var);
    }

    ShaderProgram& ShaderProgram::getDefaultShader(ShaderFile file)
    {
        initializeDefaults();
        return *_shaders._shaders[(int)file];
    }
}