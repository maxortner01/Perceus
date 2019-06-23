#pragma once

#include <math.h>
#include "Perceus/Data/Matrix.h"
#include "Perceus/Data/Transformable.h"

#include "Perceus/Core/Engine.h"
#include "Perceus/Util/Log.h"

namespace pcs
{
    class Camera : public Transformable3D<float>
    {
        Mat4f projection;

        float _FOV, _zNear, _zFar;

    public:
        Camera(float FOV = 90.f, float zNear = .01f, float zFar = 1000.f) :
            projection(), _FOV(FOV), _zNear(zNear), _zFar(zFar)
        {
            Engine::get().pushCamera((void*)this);
            Camera::makeProjection(FOV, zNear, zFar);
            PS_CORE_DEBUG("Camera created");
        }

        ~Camera()
        {
            PS_CORE_DEBUG("Camera destroyed");
        }

        Mat4f getView()
        {
            Mat4f view = Mat4f::makeTranslation(getLocation() * -1);
            //PS_CORE_WARN("Camera: {0}, {1}, {2}", view.m[0][3], view.m[1][3], view.m[2][3]);
            return view;
        }

        Mat4f getProjection()
        {
            return projection;
        }

        void makeProjection(float FOV = -1, float zNear = -11, float zFar = -1)
        {
            if (FOV == -1)   FOV = _FOV;
            if (zNear == -1) zNear = _zNear;
            if (zFar == -1)  zFar = _zFar;

            Vec2i size = Engine::get().getWindow()->getSize();
            PS_CORE_DEBUG("Camera: Window Size {0}x{1}", size.x, size.y);
            float aspectRatio = (float)size.y / (float)size.x;

            float fovRad = FOV * 3.14159f / 180.f;
            float invTan = 1.f / tanf(fovRad / 2.f);

            projection.m[0][0] = aspectRatio * invTan;
            projection.m[1][1] = invTan;
            projection.m[2][2] = zFar / (zFar - zNear);
            projection.m[2][3] = -1;
            projection.m[3][2] = (-zFar * zNear) / (zFar - zNear);
        }
    };
}