#pragma once

#include "Sizable.h"
#include "Vector.h"

namespace pcs
{
    template<typename T>
    class Transformable2D : public Sizable<T>
    {
        Vec2<T> location;

    public:
        Vec2<T> getLocation() const    { return location; }
        bool    setLocation(Vec2<T> l) { location = l; return true; }
    };
}