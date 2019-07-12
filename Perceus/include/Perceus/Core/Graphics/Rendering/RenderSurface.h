#pragma once

#include "RenderObject.h"
#include "Perceus/Data/Sizable.h"
#include "Perceus/Data/NonCopyable.h"

namespace pcs
{
namespace rend
{
    /**
     * @brief Class that handles basic rendering functionality.
     * 
     * @tparam T Type which Sizable is to be
     */
    template<typename T>
    class RenderSurface :
        public RenderObject, public Sizable<T>, public Data::NonCopyable
    {

    protected:
        /// Type-independant pointer to an object needed by the render api
        void* apiPTR = nullptr;

    public: 
        RenderSurface(const T width, const T height) :
            Sizable<T>({ width, height })
        {
            
        }

        void clear(Color color = Color(0, 0, 0)) const
        {
            rendAPI()->clear(color);
        }

        virtual void bind()   /***/ = 0;
        virtual void unbind() const = 0;

        /// Returns the api pointer
        void** getAPILoc() { return &apiPTR; }       
    };
}
}