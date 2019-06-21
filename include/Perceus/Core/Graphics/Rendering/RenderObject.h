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

        const char* getAPIName(RenderAPIType type) const
        {
            return (const char *[]){
                "OpenGL",
                "DirectX11",
                "Vulkan"
            }[type];
        }
    };

    class RenderObject
    {
    protected:
        static RenderSettings settings;

        static RenderAPI* rendAPI();
    };
}
}