#pragma once

#include "Color.h"
#include "Vector.h"

namespace pcs
{
    struct Vertex
    {
        Vec3f vertex, normal;
        Vec2f tex;
        Color color = Color(1.f, 1.f, 1.f);
    };
}