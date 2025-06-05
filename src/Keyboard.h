#ifndef KEYBOARD_H
#define KEYBOARD_H

//#include <X11/Xlib.h>

#include "Window.h"

namespace U
{

/* X11-specific */
/* It's stupid */
enum class Key
{
	Q = XK_q,
	W = XK_w,
	E = XK_e,
	R = XK_r,
	T = XK_t,
	Y = XK_y,
	U = XK_u,
	I = XK_i,
	O = XK_o,
	P = XK_p,
	A = XK_a,
	S = XK_s,
	D = XK_d,
	F = XK_f,
	G = XK_g,
	H = XK_h,
	J = XK_j,
	K = XK_k,
	L = XK_l,
	Z = XK_z,
	X = XK_x,
	C = XK_c,
	V = XK_v,
	B = XK_b,
	N = XK_n,
	M = XK_m
};

class Keyboard
{
public:
	Keyboard(const U::Window* context);
	~Keyboard();

	Keyboard(Keyboard& other) = delete;
	Keyboard& operator=(Keyboard& other) = delete;

	void Update();

	bool IsKeyPressed(Key key) const;

private:
	/* X11-specific */ 
	char m_keymap[32];
	::Display* m_display;
	::Window m_handler;	
};

};

#endif
