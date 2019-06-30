#pragma once

namespace pcs
{
namespace Data
{
    class ObjectID
    {
    protected:
        unsigned int id;

    public:
        unsigned int &getID() { return id; }
    };
}
}