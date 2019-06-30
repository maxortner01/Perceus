#include "Perceus/Core/Graphics/Rendering/Events/EventHandler.h"

namespace pcs
{
    void EventHandler::clearEvents()
    {
        events.clear();
        events.reserve(16);
        inc = 0;
    }

    EventHandler::EventHandler()
    {
        events.reserve(16);
    }   

    Event* EventHandler::getEvent()
    {
        if (inc >= events.size()) return nullptr;

        Event* r = events.at(inc++);
        
        if (r == nullptr) 
            inc = 0;

        return r;
    }
}