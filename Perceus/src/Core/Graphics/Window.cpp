#include "Perceus/Core/Graphics/Window.h"
#include "Perceus/Util/Log.h"

#include "Perceus/Core/Graphics/Rendering/OpenAPI.h"
#include "Perceus/Core/Graphics/Camera.h"
#include "Perceus/Core/Engine.h"

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

    bool Window::clear(Color color)
    {
        rendAPI()->clear(color);
        return true;
    }

    bool Window::render()
    {
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
        
        // Need to recompute projection matrices on window resize
        std::vector<void*> &c = Engine::get().getCameraDirectory();
        PS_CORE_DEBUG("Recomputing Projections for {0} camera(s) for window size {1}x{2}", c.size(), width, height);
        for (int i = 0; i < c.size(); i++)
            static_cast<Camera*>(c.at(i))->makeProjection();

        return rendAPI()->resizeWindow(this, width, height);
    }
}