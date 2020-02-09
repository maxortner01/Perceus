#pragma once

#include "Shader.h"

namespace pcs
{
<<<<<<< HEAD
    class ShaderProgram : 
        public rend::RenderObject, public Data::ObjectID<ShaderProgram>
=======
    enum class ShaderFile
>>>>>>> master
    {
		Default3D,
        Count
    };

    /**
     * @brief Represents a complete shader program.
     * Holds the objects for each shader (vertex and fragment). This is where
     * each uniform is set.
     */
    class ShaderProgram : public rend::RenderObject, public Data::ObjectID<ShaderProgram>
    {
		struct defaultShaders
		{
			defaultShaders();
            ~defaultShaders();

            std::vector<ShaderProgram*> _shaders;
			std::pair<std::string, std::string> file_contents[(int)ShaderFile::Count];
		};
		static defaultShaders _shaders;

        std::vector<Shader*> shaders;

        void destroyShaders();

        static void initializeDefaults();

    public:
        PERC_API ShaderProgram();
        PERC_API ~ShaderProgram();

        PERC_API Shader &getShader(ShaderType type);
        PERC_API bool link();

        PERC_API bool setUniform(const char* name, const Mat4f &matrix);
        PERC_API bool setUniform(const char* name, const Vec3f &var);
        PERC_API bool setUniform(const char* name, const int &var);

        PERC_API void use()   const { rendAPI()->useProgram(id); }
        PERC_API void close() const { rendAPI()->useProgram(0); }

        PERC_API static ShaderProgram& getDefaultShader(ShaderFile file);
    };
}