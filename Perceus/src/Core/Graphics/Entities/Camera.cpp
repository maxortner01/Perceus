#include "Perceus/Core/Graphics/Entities/Camera.h"

#include "Perceus/Core/Engine.h"
#include "Perceus/Data/Inc.h"

namespace pcs
{
    Camera::Camera(float FOV, float zNear, float zFar) :
            projection(), _FOV(FOV), _zNear(zNear), _zFar(zFar)
    {
        PS_CORE_DEBUG("Constructing Camera.");
        Engine::get().pushCamera((void*)this);
        Camera::makeProjection(FOV, zNear, zFar);
    }

    Mat4f Camera::getView() 
    {
        Mat4f t = Mat4f::makeTranslation(getLocation() * -1);
        Mat4f r = Mat4f::makeRotation(getRotation());
        return t * r;
    }

    void Camera::makeProjection(float FOV, float zNear, float zFar)
    {
        if (FOV == -1)   FOV = _FOV;
        if (zNear == -1) zNear = _zNear;
        if (zFar == -1)  zFar = _zFar;

        Vec2u size = Engine::get().getWindow()->getSize();
        PS_CORE_DEBUG("Camera: Window Size {0}x{1}", size.x, size.y);
        float aspectRatio = (float)size.y / (float)size.x;

        // WTF is going on here, 10 degrees behaves as if it were 100 degrees
        float fovRad = FOV / 10.f * 3.14159f / 180.f;
        float invTan = 1.f / tanf(fovRad / 2.f);

        projection.m[0][0] = aspectRatio * invTan;
        projection.m[1][1] = invTan;
        projection.m[2][2] = zFar / (zFar - zNear);
        projection.m[2][3] = -1;
        projection.m[3][2] = (-zFar * zNear) / (zFar - zNear);
    }
}
