#pragma once

#include "Event.h"

namespace pcs
{
    enum class KeyState
    {
        PRESSED,
        RELEASED,
        DOWN,
        NONE
    };

    class KeyEvent : public Event
    {
        static unsigned int _keycount;
        static int* key_states;

        char ch;

    public:
        KeyEvent(const char c, KeyState state);

        EVENT_CATEGORY(KeyboardEvent);

        char getKey() const { return ch; }
    };

    class KeyPressEvent : public KeyEvent
    {
    public:
        KeyPressEvent(const char c) : KeyEvent(c, KeyState::PRESSED) { }
        
        EVENT_TYPE(KeyPress);
    };

    class KeyReleaseEvent : public KeyEvent
    {
    public:
        KeyReleaseEvent(const char c) : KeyEvent(c, KeyState::RELEASED) { }
        
        EVENT_TYPE(KeyRelease);
    };

    class KeyDownEvent : public KeyEvent
    {
    public:
        KeyDownEvent(const char c) : KeyEvent(c, KeyState::DOWN) { }
        
        EVENT_TYPE(KeyDown);
    };
}