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
        bool renderArray(unsigned int vertexCount) const;

        // VERTEX BUFFER OBJECTS
        void makeBuffer(Buffer* buffer) const;
        void destroyBuffer(Buffer* buffer) const;
        void bindBuffer(unsigned int ID, BufferType type = BufferType::Vertex) const;
        void bindBufferData(unsigned int bytesize, const void* data, unsigned int members, unsigned int index, BufferType type = BufferType::Vertex) const;

        // VERTEX ARRAY OBJECT
        void makeBufferArray(BufferArray* array) const;
        void destroyBufferArray(BufferArray* array) const;
    };
}
}