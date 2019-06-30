#pragma once

#include "Sizable.h"
#include "Vector.h"

namespace pcs
{
    template<typename T>
    class Transformable
    {
        T location;
        T rotation;
        T scale;

    public:
        T      &getLocation()    { return location; }
        bool    setLocation(T l) { location = l; return true; }

        T      &getRotation()    { return rotation; }
        bool    setRotation(T r) { rotation = r; return true; }

        T      &getScale()       { return scale; }
        bool    setScale(T s)    { scale = s; return true; }
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