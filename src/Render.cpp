#include "Render.h"
#include "Texture.h"

U::Render::Render(U::Window* context)
{
	m_context = context;
}

void U::Render::RenderObject(const U::IGameObject* object)
{
	U::Texture& output = m_context->GetBuffer();
	for (auto it = output.Begin(); it != output.End(); ++it)
	{
		*it = { (char)255, (char)255, (char)255, (char)255 };
	}
	
	const U::Texture& texture = object->GetTexture();

	for (auto it = texture.CBegin(); it != texture.CEnd(); ++it)
	{
		int x = object->GetPosition().x + it.GetX();
		int y = output.GetHeight() - (object->GetPosition().y + it.GetY());

		bool isOutOfBound = x < 0 || x >= output.GetWidth() || y < 0 || y >= output.GetHeight();
		if (isOutOfBound)
		{
			continue;
		}
		else
		{
			output.GetTexel(x, y) = *it;
		}
	} 	
}
