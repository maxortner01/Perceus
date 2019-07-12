#pragma once

#include "RenderAPI.h"

namespace pcs
{
namespace rend
{
    /**
     * @brief Enum that holds the types of APIs
     */
    enum RenderAPIType
    {
        OpenGL,
        DirectX11,
        Vulkan
    };

    /**
     * @brief Container for choosing various API types.
     */
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

    /**
     * @brief Class for retreiving the currently selected render API.
     */
    class RenderObject
    {
    protected:
        /// Used for keeping track of the currently selected render API.
        static RenderSettings settings;

        /**
         * @brief Holds and retreives the currently selected render API interface.
         * 
         * @return RenderAPI* Currently selected render API interface.
         */
        static RenderAPI* rendAPI();
    };
}
}