#pragma once

#include <iostream>
<<<<<<< HEAD
#include <vector>
=======
#include "Perceus/Data/Inc.h"
>>>>>>> master
#include "../Rendering/RenderObject.h"

#include "Perceus/Data/ObjectID.h"
#include "Perceus/Util/Log.h"

namespace pcs
{
namespace rend
{
<<<<<<< HEAD
=======
    /**
     * @brief Index of each buffer type.
     */
>>>>>>> master
    enum class BufferIndex
    {
        Vertices,
        Normal,
        TexCoords,
        Color,
        Tangents,
        ModelMatrix,
<<<<<<< HEAD
        Indices
    };

    class Buffer : 
=======
        Indices,
        BufferCount
    };

    /**
     * @brief Handles transportation of vector-based data into the render api.
     */
    class PERC_API Buffer : 
>>>>>>> master
        public RenderObject, public Data::ObjectID<Buffer>
    {
        unsigned int _index, _count;

    public:
<<<<<<< HEAD
        Buffer(unsigned int index);

=======
        /**
         * @brief Constructs a new Buffer object
         * 
         * @param index Index of the buffer within an array object
         */
        Buffer(unsigned int index);

        /**
         * @brief Constructs a new Buffer object and binds specified data.
         * 
         * @tparam Args Arguments which correspond to a bindData function
         * @param index Index of the buffer within an array object
         * @param args Arguments which correspond to a bindData function
         */
>>>>>>> master
        template<typename... Args>
        Buffer(unsigned int index, Args... args) :
            Buffer(index)
        {
            bindData(args...);
        }

<<<<<<< HEAD
        ~Buffer();

        void bind();
        void unbind() const;

=======
        /**
         * @brief Destroys the Buffer object.
         */
        ~Buffer();

        /**
         * @brief Binds the buffer.
         */
        void bind();
        /**
         * @brief Unbinds the buffer.
         */
        void unbind() const;

        /**
         * @brief Binds the specified data to the gpu-buffer.
         * 
         * @tparam T Type of data to bind
         * @param data Pointer to the data
         * @param count Amount of items in the array
         * @param members Amount of data members per object of type T
         */
>>>>>>> master
        template<typename T>
        void bindData(T* data, unsigned int count, unsigned int members)
        {
            bind();
            rendAPI()->bindBufferData(sizeof(T) * count, data, members,true, _index);
            unbind();

            _count = count;
        }

<<<<<<< HEAD
        template<typename T>
        void bindData(std::vector<T> data, unsigned int members)
=======
        /**
         * @brief Binds the specified data to the gpu-buffer.
         * 
         * @tparam T Type of data to bind
         * @param data Vector of data 
         * @param members Amount of data members per object of type T
         */
        template<typename T>
        void bindData(const std::vector<T> &data, const unsigned int members)
>>>>>>> master
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

<<<<<<< HEAD
        void bindData(std::vector<Mat4f> &matrices)
=======
        /**
         * @brief Binds the specified list of matrices to the gpu-buffer.
         * 
         * @param matrices Vector of matrices
         */
        void bindData(const std::vector<Mat4f> &matrices)
>>>>>>> master
        {
            rendAPI()->bindBufferMatrixData(this, matrices);
        }

<<<<<<< HEAD
        unsigned int &getIndex() { return _index; }
=======
        /// Gets the current index within an array object
        unsigned int &getIndex() { return _index; }
        /// Gets the data count
>>>>>>> master
        unsigned int &getCount() { return _count; }
    };
}
}