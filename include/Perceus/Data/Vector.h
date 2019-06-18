#pragma once

namespace pcs
{
    template<typename T>
    struct Vec2
    {
        T x, y;
        
        Vec2(T _x = 0, T _y = 0) :
            x(_x), y(_y)
        {

        }

        void operator+(const Vec2<T> &v)
        {
            x += v.x;
            y += v.y;
        }

        void operator-(const Vec2<T> &v)
        {
            x -= v.x;
            y -= v.y;
        }
    };
    
    template<typename T>
    struct Vec3
    {
        T x, y, z;

        Vec3(T _x = 0, T _y = 0, T _z = 0) :
            x(_x), y(_y), z(_z)
        {

        }

        void operator+(const Vec3<T> &v)
        {
            x += v.x;
            y += v.y;
            z += v.z;
        }

        void operator-(const Vec3<T> &v)
        {
            x -= v.x;
            y -= v.y;
            z -= v.z;
        }
    };

    typedef Vec2<double> Vec2d;
    typedef Vec2<float>  Vec2f;
    typedef Vec2<int>    Vec2i;

    typedef Vec3<double> Vec3d;
    typedef Vec3<float>  Vec3f;
    typedef Vec3<int>    Vec3i;
}