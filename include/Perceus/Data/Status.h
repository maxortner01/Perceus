#pragma once

#include <vector>

namespace pcs
{
namespace Data
{

    template<class E>
    class Status
    {
        E status;

    protected:
        inline static std::vector<const char*> values;

        bool setStatus(E s) { status = s; return true; }

    public:
        E getStatus() const { return status; }

        // Strings for window status codes
        static const char* getStatusValue(int enumVal) {
            return values[enumVal];
        }
    };
}
}