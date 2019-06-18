#include "Perceus/Core/Graphics/Rendering/Events/KeyboardEvents.h"

namespace pcs
{
    unsigned int KeyEvent::_keycount = 128;
    int* KeyEvent::key_states = new int[KeyPressEvent::_keycount];

    KeyEvent::KeyEvent(const char c, KeyState state) :
        ch(c)
    {
        int keycode = (int)c;
        if (keycode > _keycount) return;

        key_states[keycode] = (int)state;
    }
}