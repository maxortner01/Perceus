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
        int makeWindow(void* windowPTR);
        int destroyWindow(void* windowPTR);
        bool shouldClose(void* windowPTR) const;
        bool swapBuffers(void* windowPTR) const;
        bool pollEvents(void* windowPTR) const;
        bool resizeWindow(void* windowPTR, unsigned int width, unsigned int height) const;
        double getTime() const;

        void test() const;

        // RENDERING
        bool clear(Color color) const;
    };
}
}