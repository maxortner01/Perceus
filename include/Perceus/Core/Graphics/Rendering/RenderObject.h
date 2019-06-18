#pragma once

#include "RenderAPI.h"

namespace pcs
{
namespace rend
{
    enum 
    {
        OpenGL,
        DirectX11,
        Vulkan
    } typedef RenderAPIType;

    struct RenderSettings
    {
        RenderAPIType api = OpenGL;
    };

    class RenderObject
    {
    protected:
        static RenderSettings settings;

        static RenderAPI* rendAPI();
    };
}
}