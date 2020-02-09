#include "Perceus/Core/Graphics/Entities/Camera.h"

#include "Perceus/Core/Engine.h"
#include "Perceus/Data/Inc.h"

<<<<<<< HEAD
namespace pcs
{
    Camera::Camera(float FOV, float zNear, float zFar) :
            projection(), _FOV(FOV), _zNear(zNear), _zFar(zFar)
    {
        PS_CORE_DEBUG("Constructing Camera.");
        Engine::get().pushCamera((void*)this);
        Camera::makeProjection(FOV, zNear, zFar);
=======
#include <cmath>

namespace pcs
{
    Camera::Camera(Window* w, float FOV, float zNear, float zFar) :
            window(w), projection(), _FOV(FOV), _zNear(zNear), _zFar(zFar)
    {
        PS_CORE_DEBUG("Constructing Camera.");
        window->pushCamera(this);
        Camera::makeProjection(FOV, zNear, zFar);
        PS_CORE_DEBUG("Done with camera.");
    }
    
    void Camera::move(const Direction direction, const float speed)
    {
        switch(direction)
        {
            case Direction::Forward:
            {
                getLocation().x += std::cos(getRotation().y + (90.f * 3.14159f / 180.f)) * speed;
                getLocation().z += std::sin(getRotation().y + (90.f * 3.14159f / 180.f)) * speed;
                return;
            }

            case Direction::Backward:
            {
                getLocation().x -= std::cos(getRotation().y + (90.f * 3.14159f / 180.f)) * speed;
                getLocation().z -= std::sin(getRotation().y + (90.f * 3.14159f / 180.f)) * speed;
                return;
            }

            case Direction::Left:
            {
                getLocation().x -= std::cos(getRotation().y) * speed;
                getLocation().z -= std::sin(getRotation().y) * speed;
                return;
            }

            case Direction::Right:
            {
                getLocation().x += std::cos(getRotation().y) * speed;
                getLocation().z += std::sin(getRotation().y) * speed;
                return;
            }
        }
>>>>>>> master
    }

    Mat4f Camera::getView() 
    {
        Mat4f t = Mat4f::makeTranslation(getLocation() * -1);
        Mat4f r = Mat4f::makeRotation(getRotation());
<<<<<<< HEAD
        return t * r;
=======
        return r * t;
    }

    void Camera::associateWindow(Window* win)
    {
        window = win;
>>>>>>> master
    }

    void Camera::makeProjection(float FOV, float zNear, float zFar)
    {
        if (FOV == -1)   FOV = _FOV;
        if (zNear == -1) zNear = _zNear;
        if (zFar == -1)  zFar = _zFar;

<<<<<<< HEAD
        Vec2u size = Engine::get().getWindow()->getSize();
=======
        PS_CORE_DEBUG("Making proj");
        std::cout << window << "\n";
        Vec2u size = window->getSize();
>>>>>>> master
        PS_CORE_DEBUG("Camera: Window Size {0}x{1}", size.x, size.y);
        float aspectRatio = (float)size.y / (float)size.x;

        // WTF is going on here, 10 degrees behaves as if it were 100 degrees
        float fovRad = FOV / 10.f * 3.14159f / 180.f;
        float invTan = 1.f / tanf(fovRad / 2.f);
<<<<<<< HEAD

        projection.m[0][0] = aspectRatio * invTan;
        projection.m[1][1] = invTan;
        projection.m[2][2] = zFar / (zFar - zNear);
        projection.m[2][3] = -1;
        projection.m[3][2] = (-zFar * zNear) / (zFar - zNear);
=======
        
        projection(0, 0) = aspectRatio * invTan;
        projection(1, 1) = invTan;
        projection(2, 2) = zFar / (zFar - zNear);
        projection(2, 3) = -1;
        projection(3, 2) = (-zFar * zNear) / (zFar - zNear);
>>>>>>> master
    }
}
