#pragma once

#include "../Proc/Proc.h"

#include "rend/VariableAPI.h"

namespace pcs
{
    class PDLL Window : public rend::VariableAPI
    {
    public:
        void hello() const;
    };
}