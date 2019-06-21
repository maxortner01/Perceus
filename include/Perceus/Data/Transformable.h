#pragma once

#include "Sizable.h"
#include "Vector.h"

namespace pcs
{
    template<typename T>
    class Transformable
    {
        T location;

    public:
        T &getLocation()         { return location; }
        bool    setLocation(T l) { location = l; return true; }
    };

    template<typename T>
    class Transformable2D : public Sizable<T>, public Transformable<Vec2<T>>
    {

    };

    template<typename T>
    class Transformable3D : public Sizable<T>, public Transformable<Vec3<T>>
    {

    };
}