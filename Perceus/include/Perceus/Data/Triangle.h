#pragma once

#include <iostream>
#include "Vector.h"

namespace pcs
{
    /**
     * @brief Object that holds the values for determining properties of a triangle.
     * 
     * By default this object is set to work in a 3D environment. For 2D environments
     * see Triangle2D.
     */
    class Triangle
    {
        Vec3f a, b, c;

    public:
        Triangle(Vec3f _a, Vec3f _b, Vec3f _c) :
            a(_a), b(_b), c(_c)
        {
                
        }

        /**
         * @brief Calculates the normal of the triangle.
         * @return Vec3f The normal vector of the triangle.
         */
        Vec3f getNormal() const
        {
            Vec3f edge1 = b - a;
            Vec3f edge2 = b - c;

            return cross(edge1, edge2);
        }
    };

    /**
     * @brief Two-dimensional representation of a triangle.
     */
    class Triangle2D : public Triangle
    {
    public:
        Triangle2D(Vec2f _a, Vec2f _b, Vec2f _c) :
            Triangle(Vec3f(_a.x, _a.y, 0), Vec3f(_b.x, _b.y, 0), Vec3f(_c.x, _c.y, 0))
        {

        }
    };
}