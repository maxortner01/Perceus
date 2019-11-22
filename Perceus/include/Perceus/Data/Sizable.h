#pragma once

#include "Vector.h"

namespace pcs
{
    /**
     * @brief Basic functionality for something that has a width and height.
     * @tparam T Type of the variables that store the width and height.
     */
    template<typename T>
    struct Sizable
    {
        Vec2<T> size;

    public:
        Sizable() { }
        Sizable(Vec2<T> s) :
            size(s)
        {
            
        }

        Vec2<T> getSize() const { return size; }
        bool    setSize(Vec2<T> s) { size = s; return true; }
    };
}