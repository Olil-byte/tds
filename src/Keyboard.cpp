#include "Keyboard.h"

U::Keyboard::Keyboard(const U::Window* context)
{
	/* X11-specific */
	m_display = context->X11GetDisplay();
	m_handler = context->X11GetHandler();
}

U::Keyboard::~Keyboard()
{
	
}

void U::Keyboard::Update()
{
	XQueryKeymap(m_display, m_keymap);
}

bool U::Keyboard::IsKeyPressed(U::Key key) const
{
	::KeyCode keycode = XKeysymToKeycode(m_display, (KeySym)key);
	
	return m_keymap[keycode >> 3] & (1 << (keycode & 7));
}
