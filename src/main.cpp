#include "Window.h"
#include "Keyboard.h"
#include "Render.h"

#include "Renderable.h"

#include <stdio.h>

int main(void)
{
	U::Window window = U::Window("tds", 800, 600);
	U::Keyboard keyboard = U::Keyboard(&window); 
	U::Render render = U::Render(&window);
	
	U::IRenderable* square = new U::Square(50, 50, 50, 50);

	window.Show();

	while (true)
	{
		keyboard.Update();
		if (keyboard.IsKeyPressed(U::Key::W))
		{
			square->SetY(square->GetY() + 1);
		}
		if (keyboard.IsKeyPressed(U::Key::A))
		{
			square->SetX(square->GetX() - 1);
		}
		if (keyboard.IsKeyPressed(U::Key::S))
		{
			square->SetY(square->GetY() - 1);
		}
		if (keyboard.IsKeyPressed(U::Key::D))
		{
			square->SetX(square->GetX() + 1);
		}
		
		render.RenderObject(square);
		window.Display();
	}

	delete square;

	return 0;
}
