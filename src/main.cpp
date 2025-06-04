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
	while (true)
	{
		int n = XPending((::Display*)window.GetDisplay());
		for (int i = 0; i < n; i++)
		{
			XEvent event;
			XNextEvent((::Display*)window.GetDisplay(), &event);
			switch (event.type)
			{
			case KeyPress:
				switch (XLookupKeysym(&event.xkey, 0))
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
					square->SetY(square->GetY() + 1);
					break;
				}
				
				break;
			}
		}
		
		
		render.RenderObject(square);
		window.Display();
	}

	delete square;

	return 0;
}
