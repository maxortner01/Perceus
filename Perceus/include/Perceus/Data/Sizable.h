#pragma once

#include "Vector.h"

namespace pcs
{
    template<typename T>
    struct Sizable
    {
        Vec2<T> size;

    public:
        Vec2<T> getSize() const { return size; }
        bool    setSize(Vec2<T> s) { size = s; return true; }
    };
}