#pragma once

#include "RawModel.h"

namespace pcs
{
    class Model
    {
        RawModel* rawModel;
    public:
    
        RawModel* getRawModel() { return rawModel; }
    };
}