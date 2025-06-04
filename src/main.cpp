//#include <X11/Xlib.h>

#include "Window.h"
#include "Render.h"
#include "Renderable.h"

int main(void)
{
	U::Window window = U::Window("tds", 800, 600);
	U::Render render = U::Render(&window);

	U::IRenderable* square = new U::Square(50, 50, 50, 50);

	window.Show();

	while (true)
	{
		square->SetX(square->GetX() + 1);
		render.RenderObject(square);
		window.Display();
	}

	delete square;

	return 0;
}
