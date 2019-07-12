#include "Perceus/Core/Graphics/Window.h"

#include "Perceus/Core/Graphics/Entities/Camera.h"
#include "Perceus/Core/Engine.h"
#include "Perceus/Util/Log.h"
#include "Perceus/Util/Memory/RegTable.h"

#include <iostream>

namespace pcs
{
    // Window constructor

    Window::Window(const unsigned int width, const unsigned int height) :
        RenderSurface(width, height), ObjectUID()
    {
        PS_CORE_DEBUG("Constructing Window");

        getValues() = {
			"Ok",
			"API failed to initialize",
			"Window failed to create",
            "None"
        };

        setSize({ width, height });
        
        int windowStatus = rendAPI()->makeWindow(this);
        setStatus((WindowStatus)windowStatus);
    }

	// Window destructor	

    Window::~Window()
    {
        rendAPI()->destroyWindow(this);
        PS_CORE_WARN("Window ({0}) destroyed", getID());
    }

	// Static window creation method

    Window* Window::Create(const unsigned int width, const unsigned int height)
    {
        using namespace Util::Mem;

        Window* win = new Window(width, height);
        std::cout << "Window made: " << win << std::endl;
        RegTable::get().registerObject<Window>(win->getID(), win);

        if (win->getStatus() > WindowStatus::Ok)
            PS_CORE_ERROR("Window ({0}) failed to initialize with status {1}: {2}", 
                win->getID(), (int)win->getStatus(), win->getStatusValue());
        else
            PS_CORE_INFO("Initialized window ({0}). Status {1}: {2}", 
                win->getID(), (int)win->getStatus(), win->getStatusValue());

        return win;
    }

	// Window is open method

    bool Window::isOpen()
    {
        return !rendAPI()->shouldClose(this);
    }

    bool Window::render()
    {
        return rendAPI()->swapBuffers(this);
    }

    void Window::bind() 
    {
        rendAPI()->makeContextCurrent(this);
    }

    void Window::unbind() const 
    {

    }


    bool Window::pollEvents()
    {
        return rendAPI()->pollEvents(this);
    }

	// Resize window method

    bool Window::resize(unsigned int width, unsigned int height)
    {
        using namespace Util::Mem;

        setSize({ width, height });
        
        // Need to recompute projection matrices on window resize
        std::vector<void*> &c = Engine::get().getCameraDirectory();
        PS_CORE_DEBUG("Recomputing Projections for {0} camera(s) for window size {1}x{2}", c.size(), width, height);
        for (int i = 0; i < c.size(); i++)
            static_cast<Camera*>(c.at(i))->makeProjection();

        return rendAPI()->resizeWindow(this, width, height);
    }
}
