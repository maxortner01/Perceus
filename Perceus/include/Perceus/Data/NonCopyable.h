#pragma once

namespace pcs
{
namespace Data
{
    struct NonCopyable
    {
    protected:
        NonCopyable() {}
        ~NonCopyable() {}

    public:
        NonCopyable(const NonCopyable&);
        NonCopyable& operator= (const NonCopyable&);
    };
}
}