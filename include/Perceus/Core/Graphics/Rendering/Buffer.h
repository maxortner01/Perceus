#pragma once

#include <vector>
#include "RenderObject.h"

#include "Perceus/Util/Log.h"

namespace pcs
{
namespace rend
{

    class Buffer : public RenderObject
    {
        unsigned int id, _index;

    public:
        Buffer(unsigned int index);

        template<typename... Args>
        Buffer(unsigned int index, Args... args) :
            Buffer(index)
        {
            bindData(args...);
        }

        ~Buffer();

        void bind()   const { rendAPI()->bindBuffer(id); }
        void unbind() const { rendAPI()->bindBuffer(0);  }

        template<typename T>
        void bindData(T* data, unsigned int count, unsigned int members)
        {
            bind();
            rendAPI()->bindBufferData(sizeof(T) * count, data, members, _index);
            unbind();
        }

        template<typename T>
        void bindData(std::vector<T> data, unsigned int members)
        {
            bind();
            rendAPI()->bindBufferData(sizeof(T) * data.size(), &data[0], members, _index);
            unbind();
        }

        unsigned int &getID()    { return id; }
        unsigned int &getIndex() { return _index; }
    };
}
}