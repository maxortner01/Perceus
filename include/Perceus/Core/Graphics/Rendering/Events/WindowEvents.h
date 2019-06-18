#pragma once

#include "Event.h"

namespace pcs
{
    class WindowClosedEvent : public Event
    {
    public:
        EVENT_CATEGORY(WindowEvent);
        EVENT_TYPE(WindowClosed);
    };
}