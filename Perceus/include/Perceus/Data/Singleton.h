#pragma once

namespace pcs
{
namespace Data
{
    /**
     * @brief Basic functionality for a class that has only one instance.
     * 
     * @tparam T Type of the class to make a singleton.
     */
    template<typename T>
    class Singleton
    {
    public:
        static T &get()
        {
            static T* t;

            if (t == nullptr)
                t = new T();

            return *t;
        }
    };
}
}