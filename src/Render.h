#ifndef RENDER_H
#define RENDER_H

#include "Window.h"
#include "Renderable.h"

namespace U
{

class Render
{
public:
	Render(Window* context);

	void RenderObject(const IRenderable* renderable);

	// Deprecated
	// void RenderInto(Buffer& buffer);
	// void RenderInto(Window& window);
	// void RenderItInto(IRenderable& renderable, Window& window);
private:
	Window* m_context;
	
};

};

#endif
