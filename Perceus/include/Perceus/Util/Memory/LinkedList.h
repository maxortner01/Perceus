#pragma once

#include <stdexcept>
#include "../Data/Inc.h"

namespace pcs
{
namespace Util
{
    template<typename T>
    class LinkedList
    {
        struct _Point
        {
            T  value;
            _Point* last = nullptr;
            _Point* next = nullptr;
        };

        size_t  _size;
        _Point* first;
        _Point* last;

    public:
        LinkedList() :
            size(0), first(nullptr), last(nullptr)
        {
            
        }

        void push(T&& val);

        size_t size() const;

        T &operator[](size_t index);
    };

    // Push function

    template<typename T>
<<<<<<< HEAD
    void LinkedList<T>::push(T&& val)
=======
    void Linkedstd::vector<T>::push(T&& val)
>>>>>>> master
    {
        _Point* p = new _Point;
        p->value = T(std::forward<T>(val));

        if (!first)
            first = p;

        if (last)
        {
            p->last = last;
            last->next = p;
        }

        _size++;

        last = p;
    }

    // Size function

    template<typename T>
<<<<<<< HEAD
    size_t LinkedList<T>::size() const
=======
    size_t Linkedstd::vector<T>::size() const
>>>>>>> master
    {
        return _size;
    }

    // Index operator overload

    template<typename T>
<<<<<<< HEAD
    T &LinkedList<T>::operator[](size_t index)
=======
    T &Linkedstd::vector<T>::operator[](size_t index)
>>>>>>> master
    {
        _Point p = first;

        for (int i = 0; i < index; i++)
        {
            p = p->next;

            if (!p) 
                throw std::runtime_error("Index exceeds size");
        }

        return p->value;
    }
}
}