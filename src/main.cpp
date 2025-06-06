#include "Window.h"
#include "Keyboard.h"
#include "Render.h"

//#include "Renderable.h"
#include "GameObject.h"

#include <stdio.h>

#include <time.h>

#include "Solver.hpp"

int main(void)
{
	U::Window window = U::Window("tds", 800, 600);
	U::Keyboard keyboard = U::Keyboard(&window);

	U::Texture* background = new U::Texture(800, 600);
		for (auto it = background->Begin(); it != background->End(); ++it)
		{
			*it = { (char)255, (char)255, (char)255, (char)255 };
		}
		
	U::Render render = U::Render(&window, background);
	U::Solver solver = U::Solver();
	
	U::Actor* actor = new U::Actor(&keyboard);
	U::Wall* wall = new U::Wall();

	window.Show();

	float dt = 0.0f;
	clock_t lastTime = clock();
	while (true)
	{
		clock_t currentTime = clock();
		dt = (float)(currentTime - lastTime) / CLOCKS_PER_SEC;
		
		keyboard.Update();
		actor->Update(dt);
		wall->Update(dt);

		solver.AABBvsAABB(actor, wall);

		render.RenderBackground();
		render.RenderObject(actor);
		render.RenderObject(wall);
		
		window.Display();

		lastTime = currentTime;
	}

	delete background;

	delete actor;
	delete wall;

	return 0;
}
