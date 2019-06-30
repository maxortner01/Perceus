#pragma once

#include "Perceus/Data/Singleton.h"
#include "RenderAPI.h"

namespace pcs
{
namespace rend
{
    struct OpenAPI : public RenderAPI, public Data::Singleton<OpenAPI>
    {

        bool initialize();
        bool terminate();

        // WINDOW
        friend class Window;
        int makeWindow(Window* window);
        int destroyWindow(Window* window);
        bool shouldClose(Window* window) const;
        bool swapBuffers(Window* window) const;
        bool pollEvents(Window* window) const;
        bool resizeWindow(Window* window, unsigned int width, unsigned int height) const;
        double getTime() const;

        void test() const;

        // RENDERING
        bool clear(Color color) const;
        bool renderInstanced(unsigned int vertexCount, unsigned int count = 1);

        // VERTEX BUFFER OBJECTS
        void makeBuffer(Buffer* buffer) const;
        void destroyBuffer(Buffer* buffer) const;
        void bindBufferMatrixData(Buffer* buffer, std::vector<Mat4f> &matrices) const;
        void unbindBuffer(BufferType type = BufferType::Vertex) const;
        void bindBuffer(Buffer* buffer, BufferType type = BufferType::Vertex) const;
        void bindBufferData(unsigned int bytesize, const void* data, unsigned int members, unsigned int index, bool divided = true, BufferType type = BufferType::Vertex) const;

        // VERTEX ARRAY OBJECT
        void makeBufferArray(BufferArray* array) const;
        void destroyBufferArray(BufferArray* array) const;
        void bindBufferArray(unsigned int ID) const;

        // SHADER PROGRAM
        bool makeProgram(ShaderProgram* program) const;
        bool linkProgram(ShaderProgram* program) const;
        void useProgram(unsigned int id) const;
        bool destroyProgram(ShaderProgram* program) const;
        bool setUniform(ShaderProgram* program, const char* uniform_name, const Mat4f &matrix) const;
        bool setUniform(ShaderProgram* program, const char* uniform_name, const Vec3f &var) const;
        bool setUniform(ShaderProgram* program, const char* uniform_name, const int &var) const;

        // SHADERS
        bool makeShader(Shader* shader) const;
        bool compileShader(Shader* shader, const char* source) const;
        bool destroyShader(Shader* shader) const;

        // TEXTURES
        bool makeTexture(Texture* texture) const;
        bool destroyTexture(Texture* texture) const;
        void bindTexture(unsigned id, unsigned int layer = 0) const;
        bool loadImageToTexture(Texture* texture, unsigned char* img, unsigned int width, unsigned int height) const;
    };
}
}