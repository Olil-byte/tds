#ifndef WINDOW_H
#define WINDOW_H

#include <X11/Xlib.h>
#include <X11/Xutil.h>

#include "Texture.h"

namespace U
{

class Window
{
public:
	Window(const char* title, unsigned int width, unsigned int height);
	~Window();

	void Show();
	void Hide();

	void Display();

	U::Texture& GetBuffer();

private:
	int m_width;
	int m_height;

	::Window m_handler;

	::Display* m_display;
	int m_screen;
	XVisualInfo m_spec;

/* Rendering */
	::XImage* m_canvas;
	GC m_gc;
	U::Texture m_buffer;
};

};

#endif
