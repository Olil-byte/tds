#include "Window.h"

#include <stdio.h>

U::Window::Window(const char* title, unsigned int width, unsigned int height) : m_buffer(width, height)
{
	m_display = XOpenDisplay(NULL); /* Connect to standart X-Server */
	m_screen = XDefaultScreen(m_display);
	m_handler = XCreateSimpleWindow
	(
		m_display,
		DefaultRootWindow(m_display),
		0,
		0,
		width,
		height,
		0,
		0,
		0xffffffff
	);
	XStoreName(m_display, m_handler, title);

	m_width = width;
	m_height = height;

	Status status = XMatchVisualInfo
	(
		m_display,
		m_screen,
		24,
		TrueColor,
		&m_spec
	);
	if (!status)
	{
		printf("Sorry, your device is not supported :(\n");
	}

	m_canvas = XCreateImage
	(
		m_display,
		m_spec.visual,
		24,
		ZPixmap,
		0,
		(char*)m_buffer.GetData(),
		width,
		height,
		32,
		0
	);

	m_gc = XCreateGC(m_display, m_handler, 0, NULL);
}

U::Window::~Window()
{
	XCloseDisplay(m_display);
}

void U::Window::Show()
{
	XMapWindow(m_display, m_handler);
}

void U::Window::Hide()
{
	XUnmapWindow(m_display, m_handler);
}

void U::Window::Display()
{
	XPutImage(m_display, m_handler, m_gc, m_canvas, 0, 0, 0, 0, m_width, m_height);
	XFlush(m_display);
}

U::Texture& U::Window::GetBuffer()
{
	return m_buffer;
}
