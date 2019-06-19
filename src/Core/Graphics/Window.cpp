#include "Perceus/Core/Graphics/Window.h"
#include "Perceus/Util/Log.h"

#include "Perceus/Core/Graphics/Rendering/OpenAPI.h"

namespace pcs
{
    unsigned int Window::_id = 0;

    // GL Window stuff
    Window::Window(unsigned int width, unsigned int height)
    {
        values = {
            "Failed to intialize api",
            "Failed to create window",
            "OK",
            "NONE"
        };

        setSize({ (int)width, (int)height });
        
        int windowStatus = rendAPI()->makeWindow(this);
        setStatus((WindowStatus)windowStatus);
    }

    Window::~Window()
    {
        rendAPI()->destroyWindow(this);
        PS_CORE_WARN("Window ({0}) destroyed", getID());
    }

    Window* Window::Create(unsigned int width, unsigned int height)
    {
        Window* win = new Window(width, height);

        win->ID = ++win->_id;

        if (win->getStatus() != WindowStatus::OK)
            PS_CORE_ERROR("Window ({0}) failed to initialize with status {1}: {2}", 
                win->getID(), (int)win->getStatus(), getStatusValue((int)win->getStatus()));
        else
            PS_CORE_INFO("Initialized window ({0}). Status {1}", 
                win->getID(), getStatusValue((int)win->getStatus()));

        return win;
    }

    bool Window::isOpen()
    {
        return !rendAPI()->shouldClose(this);
    }

    bool Window::render()
    {
        rendAPI()->clear(Color( 1.f, 0.f, 0.f ));
        rendAPI()->test();
        return rendAPI()->swapBuffers(this);
    }

    bool Window::pollEvents()
    {
        return rendAPI()->pollEvents(this);
    }

    bool Window::resize(unsigned int width, unsigned int height)
    {
        setSize({ (int)width, (int)height });
        return rendAPI()->resizeWindow(this, width, height);
    }
}