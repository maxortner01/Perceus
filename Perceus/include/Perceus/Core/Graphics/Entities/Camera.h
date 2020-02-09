#pragma once

#include "Perceus/Data/Matrix.h"
#include "Perceus/Data/Transformable.h"
#include "Perceus/Data/ObjectID.h"

#include "Perceus/Core/Graphics/Window.h"
#include "Perceus/Util/Log.h"

namespace pcs
{
<<<<<<< HEAD
    class Camera : 
        public Transformable3D<float>, public Data::ObjectUID
    {
        Mat4f projection;
=======
    enum class Direction
    {
        Forward,
        Backward,
        Left,
        Right
    };

    class PERC_API Camera : 
        public Transformable3D<float>, public Data::ObjectUID
    {
        Mat4f projection;
        
        Window* window;
>>>>>>> master

        float _FOV, _zNear, _zFar;

    public:
<<<<<<< HEAD
        Camera(float FOV = 90.f, float zNear = .01f, float zFar = 1000.f);
=======
        Camera(Window* w, float FOV = 90.f, float zNear = .01f, float zFar = 1000.f);
>>>>>>> master

        ~Camera()
        {
            PS_CORE_DEBUG("Camera destroyed");
        }

<<<<<<< HEAD
=======
        void move(const Direction direction, const float speed);

>>>>>>> master
        Mat4f getView();

        Mat4f getProjection() const
        {
            return projection;
        }

        void associateWindow(Window* win);

        void makeProjection(float FOV = -1, float zNear = -11, float zFar = -1);
    };
}