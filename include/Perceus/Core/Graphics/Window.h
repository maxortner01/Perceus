#pragma once

#include "Perceus/Data/Status.h"
#include "Rendering/RenderObject.h"
#include "Perceus/Data/Transformable.h"

namespace pcs
{
    enum class WindowStatus
    {
        API_INIT_FAILED,
        WINDOW_CREATION_FAILED,
        OK,
        NONE,
        SIZE
    };

    class Window : public Transformable2D<int>, public rend::RenderObject, public Data::Status<WindowStatus>
    {
        friend class Engine;

        static unsigned int _id;
        unsigned int ID;

        void* apiPTR = nullptr;

    public:
        Window(unsigned int width, unsigned int height);
        virtual ~Window();

        static Window* Create(unsigned int width, unsigned int height);

        bool isOpen() const;
        bool render();
        bool resize(unsigned int width, unsigned int height);

        unsigned int getID() const { return ID; }
        void** getAPILoc() { return &apiPTR; }

    };
}