#pragma once

#include "Perceus/Data/Matrix.h"
#include "Perceus/Data/Transformable.h"
#include "Perceus/Data/ObjectID.h"

#include "Perceus/Core/Graphics/Window.h"
#include "Perceus/Util/Log.h"

namespace pcs
{
    class Camera : 
        public Transformable3D<float>, public Data::ObjectUID
    {
        Mat4f projection;

        float _FOV, _zNear, _zFar;

    public:
        Camera(float FOV = 90.f, float zNear = .01f, float zFar = 1000.f);

        ~Camera()
        {
            PS_CORE_DEBUG("Camera destroyed");
        }

        Mat4f getView();

        Mat4f getProjection() const
        {
            return projection;
        }

        void associateWindow(Window* win);

        void makeProjection(float FOV = -1, float zNear = -11, float zFar = -1);
    };
}