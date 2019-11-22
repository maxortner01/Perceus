#pragma once

#include "Perceus/Data/Inc.h"
#include "RawModelParser.h"

namespace pcs
{
    class PERC_API ParserOBJ : public Util::RawModelParser
    {
    public:
        using Util::RawModelParser::RawModelParser;

        VertexArray* parseFile() const override;
    };
}