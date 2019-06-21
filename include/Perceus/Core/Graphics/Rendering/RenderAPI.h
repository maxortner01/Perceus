#pragma once

#include "Perceus/Data/Color.h"

namespace pcs
{
class Window;
class Shader;
class ShaderProgram;

namespace rend
{
    class Buffer;
    class BufferArray;

    enum class BufferType
    {
        Vertex,
        Index
    };

    struct RenderAPI
    {
        virtual bool initialize() = 0;
        virtual bool terminate() = 0;

        // WINDOW
        virtual int makeWindow(Window* window) = 0;
        virtual int destroyWindow(Window* window) = 0;
        virtual bool shouldClose(Window* window) const = 0;
        virtual bool swapBuffers(Window* window) const = 0;
        virtual bool pollEvents(Window* window) const = 0;
        virtual bool resizeWindow(Window* window, unsigned int width, unsigned int height) const = 0;
        virtual double getTime() const = 0;

        virtual void test() const = 0;

        // RENDERING
        virtual bool clear(Color color) const = 0;
        virtual bool renderInstanced(unsigned int vertexCount, unsigned int count = 1) = 0;

        // VERTEX BUFFER OBJECT
        virtual void makeBuffer(Buffer* buffer) const = 0;
        virtual void destroyBuffer(Buffer* buffer) const = 0;
        virtual void unbindBuffer(BufferType type = BufferType::Vertex) const = 0;
        virtual void bindBuffer(Buffer* buffer, BufferType type = BufferType::Vertex) const = 0;
        virtual void bindBufferData(unsigned int bytesize, const void* data, unsigned int members, unsigned int index, bool divided = true, BufferType type = BufferType::Vertex) const = 0;

        // VERTEX ARRAY OBJECT
        virtual void makeBufferArray(BufferArray* array) const = 0;
        virtual void destroyBufferArray(BufferArray* array) const = 0;

        // SHADER PROGRAM
        virtual bool makeProgram(ShaderProgram* program) const = 0;
        virtual bool linkProgram(ShaderProgram* program) const = 0;
        virtual void useProgram(unsigned int id) const = 0;
        virtual bool destroyProgram(ShaderProgram* program) const = 0;

        // SHADERS
        virtual bool makeShader(Shader* shader) const = 0;
        virtual bool compileShader(Shader* shader, const char* source) const = 0;
        virtual bool destroyShader(Shader* shader) const = 0;

        unsigned int &getRenderCalls() { return renderCalls; }
        unsigned int &getVertexCount() { return vertexCount; }
        unsigned int &getObjectCount() { return objectCount; }

    protected:
        unsigned int renderCalls = 0;
        unsigned int vertexCount = 0;
        unsigned int objectCount = 0;
    };
}
}