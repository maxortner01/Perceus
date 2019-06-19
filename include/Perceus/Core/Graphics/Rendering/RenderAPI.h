#pragma once

#include "Perceus/Data/Color.h"

namespace pcs
{
class Window;

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

        // VERTEX BUFFER OBJECT
        virtual void makeBuffer(Buffer* buffer) const = 0;
        virtual void destroyBuffer(Buffer* buffer) const = 0;
        virtual void bindBuffer(unsigned int ID, BufferType type = BufferType::Vertex) const = 0;
        virtual void bindBufferData(unsigned int bytesize, const void* data, unsigned int members, unsigned int index, BufferType type = BufferType::Vertex) const = 0;

        // VERTEX ARRAY OBJECT
        virtual void makeBufferArray(BufferArray* array) const = 0;
        virtual void destroyBufferArray(BufferArray* array) const = 0;
    };
}
}