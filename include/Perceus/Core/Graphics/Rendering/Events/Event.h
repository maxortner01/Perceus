#pragma once

namespace pcs
{

#define EVENT_TYPE(type)    EventType getType()   const override { return EventType::type; }\
                            const char* getName() const override { return #type; }

#define EVENT_CATEGORY(category) int getCategoryFlags() const override { return EventCategory::category; }\
                                 const char* getCategory() const override { return #category; }

#define _BIT(x) (1<<x)

    enum class EventType
    {
        None,
        WindowClosed,
        KeyPress, KeyRelease, KeyDown
    };

    enum EventCategory
    {
        WindowEvent   = _BIT(1),
        KeyboardEvent = _BIT(2)
    };

    class Event
    {
    protected:
        bool handled = false;

    public:
        virtual int getCategoryFlags() const = 0;
        virtual const char* getCategory() const = 0;

        virtual EventType getType() const = 0;
        virtual const char* getName() const = 0;

        bool inCategory(EventCategory category)
        {
            return getCategoryFlags() && category;
        }
    };
}