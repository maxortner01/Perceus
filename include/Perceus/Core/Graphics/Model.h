#pragma once

#include "Perceus/Data/Transformable.h"
#include "RawModel.h"

namespace pcs
{
    class Model : public Transformable3D<float>
    {
        RawModel* rawModel;
    public:
        Model(RawModel* rm) : rawModel(rm) {}

        virtual void update() { }

        RawModel* getRawModel() { return rawModel; }
    };
}