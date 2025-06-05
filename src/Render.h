#ifndef RENDER_H
#define RENDER_H

#include "Window.h"
#include "GameObject.h"

namespace U
{

class Render
{
public:
	Render(Window* context);

	void RenderObject(const IGameObject* object);

private:
	Window* m_context;
	
};

};

#endif
