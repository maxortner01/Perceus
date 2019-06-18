#pragma once

#include "Perceus/Data/Color.h"

namespace pcs
{
namespace rend
{
    struct RenderAPI
    {
        virtual bool initialize() = 0;
        virtual bool terminate() = 0;

        // WINDOW
        virtual int makeWindow(void* windowPTR) = 0;
        virtual int destroyWindow(void* windowPTR) = 0;
        virtual bool shouldClose(void* windowPTR) const = 0;
        virtual bool swapBuffers(void* windowPTR) const = 0;
        virtual bool pollEvents(void* windowPTR) const = 0;
        virtual bool resizeWindow(void* windowPTR, unsigned int width, unsigned int height) const = 0;
        virtual double getTime() const = 0;

        virtual void test() const = 0;

        // RENDERING
        virtual bool clear(Color color) const = 0;
    };
}
}