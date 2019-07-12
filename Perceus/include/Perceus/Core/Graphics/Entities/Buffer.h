#pragma once

#include <iostream>
#include <vector>
#include "../Rendering/RenderObject.h"

#include "Perceus/Data/ObjectID.h"
#include "Perceus/Util/Log.h"

namespace pcs
{
namespace rend
{
    enum class BufferIndex
    {
        Vertices,
        Normal,
        TexCoords,
        Color,
        Tangents,
        ModelMatrix,
        Indices
    };

    class Buffer : 
        public RenderObject, public Data::ObjectID<Buffer>
    {
        unsigned int _index, _count;

    public:
        Buffer(unsigned int index);

        template<typename... Args>
        Buffer(unsigned int index, Args... args) :
            Buffer(index)
        {
            bindData(args...);
        }

        ~Buffer();

        void bind();
        void unbind() const;

        template<typename T>
        void bindData(T* data, unsigned int count, unsigned int members)
        {
            bind();
            rendAPI()->bindBufferData(sizeof(T) * count, data, members,true, _index);
            unbind();

            _count = count;
        }

        template<typename T>
        void bindData(std::vector<T> data, unsigned int members)
        {
            bind();
            BufferType type = BufferType::Vertex;
            bool divided = true;

            if (_index == (int)BufferIndex::Indices)
                type = BufferType::Index;

            rendAPI()->bindBufferData(sizeof(T) * data.size(), &data[0], members, _index, divided, type);
            unbind();

            _count = data.size();
        }

        void bindData(std::vector<Mat4f> &matrices)
        {
            rendAPI()->bindBufferMatrixData(this, matrices);
        }

        unsigned int &getIndex() { return _index; }
        unsigned int &getCount() { return _count; }
    };
}
}