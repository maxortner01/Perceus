#pragma once

#include "RenderObject.h"
#include "Perceus/Data/Sizable.h"
<<<<<<< HEAD
#include "Perceus/Data/NonCopyable.h"
=======
>>>>>>> master

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
<<<<<<< HEAD
        public RenderObject, public Sizable<T>, public Data::NonCopyable
=======
        public RenderObject, public Sizable<T>
>>>>>>> master
    {

    protected:
        /// Type-independant pointer to an object needed by the render api
        void* apiPTR = nullptr;

    public: 
<<<<<<< HEAD
=======
        /**
         * @brief Constructs a new Render Surface object.
         * 
         * @param width  Width of the surface (in px)
         * @param height Height of the surface (in px)
         */
>>>>>>> master
        RenderSurface(const T width, const T height) :
            Sizable<T>({ width, height })
        {
            
        }

<<<<<<< HEAD
=======
        /**
         * @brief Clears the current context.
         * 
         * @param color color which to clear the buffer to
         */
>>>>>>> master
        void clear(Color color = Color(0, 0, 0)) const
        {
            rendAPI()->clear(color);
        }

<<<<<<< HEAD
        virtual void bind()   /***/ = 0;
=======
        /// Binds the current surface.
        virtual void bind()   /***/ = 0;
        /// Unbinds the current surface
>>>>>>> master
        virtual void unbind() const = 0;

        /// Returns the api pointer
        void** getAPILoc() { return &apiPTR; }       
    };
}
}