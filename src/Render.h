#ifndef RENDER_H
#define RENDER_H

#include "Window.h"
#include "GameObject.h"

namespace U
{

class Render
{
public:
	Render(Window* context, U::Texture* background = nullptr);

	void RenderObject(const GameObject* object);

	void RenderBackground();

private:
	Window* m_context;
	U::Texture* m_background;
	
};

};

#endif
