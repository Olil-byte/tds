#include "Window.h"
#include "Keyboard.h"
#include "Render.h"

//#include "Renderable.h"
#include "GameObject.h"

#include <stdio.h>

#include <time.h>

int main(void)
{
	U::Window window = U::Window("tds", 800, 600);
	U::Keyboard keyboard = U::Keyboard(&window); 
	U::Render render = U::Render(&window);
	
	U::Actor* actor = new U::Actor(&keyboard);

	window.Show();

	float dt = 0.0f;
	clock_t lastTime = clock();
	while (true)
	{
		clock_t currentTime = clock();
		dt = (float)(currentTime - lastTime) / CLOCKS_PER_SEC;
		
		keyboard.Update();
		actor->Update(dt);
		
		render.RenderObject(actor);
		window.Display();

		lastTime = currentTime;
	}

	delete actor;

	return 0;
}
