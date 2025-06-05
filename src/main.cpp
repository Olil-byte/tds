#include "Window.h"
#include "Render.h"
#include "Renderable.h"

#include <stdio.h>

int main(void)
{
	U::Window window = U::Window("tds", 800, 600);
	U::Render render = U::Render(&window);

	U::IRenderable* square = new U::Square(50, 50, 50, 50);

	window.Show();

	XSelectInput((::Display*)window.GetDisplay(), *((::Window*)window.GetHandler()), KeyPressMask);
	KeyCode w_key = XKeysymToKeycode((::Display*)window.GetDisplay(), XK_w);
	KeyCode s_key = XKeysymToKeycode((::Display*)window.GetDisplay(), XK_s);
	KeyCode a_key = XKeysymToKeycode((::Display*)window.GetDisplay(), XK_a);
	KeyCode d_key = XKeysymToKeycode((::Display*)window.GetDisplay(), XK_d);
	while (true)
	{
		int n = XPending((::Display*)window.GetDisplay());
		for (int i = 0; i < n; i++)
		{
			char keymap[32];
			XQueryKeymap((::Display*)window.GetDisplay(), keymap);
			if (keymap[w_key >> 3] & (1 << (w_key & 7)))
			{
				square->SetY(square->GetY() + 1);
			}
			if (keymap[s_key >> 3] & (1 << (s_key & 7)))
			{
				square->SetY(square->GetY() - 1);
			}
			if (keymap[a_key >> 3] & (1 << (a_key & 7)))
			{
				square->SetX(square->GetX() - 1);
			}
			if (keymap[d_key >> 3] & (1 << (d_key & 7)))
			{
				square->SetX(square->GetX() + 1);
			}
			

			switch (0)
			{
			case XK_a:
				square->SetX(square->GetX() - 1);
				break;
								
			case XK_s:
				square->SetY(square->GetY() - 1);
				break;
				
			case XK_d:
				square->SetX(square->GetX() + 1);
				break;
				
			case XK_w:
				
				break;
			}
		}
		
		
		render.RenderObject(square);
		window.Display();
	}

	delete square;

	return 0;
}
