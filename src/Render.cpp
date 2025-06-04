#include "Render.h"
#include "Texture.h"

U::Render::Render(U::Window* context)
{
	m_context = context;
}

void U::Render::RenderObject(const U::IRenderable* renderable)
{
	U::Texture& output = m_context->GetBuffer();
	for (auto it = output.Begin(); it != output.End(); ++it)
	{
		*it = { (char)255, (char)255, (char)255, (char)255 };
	}
	
	
	const U::Texture& texture = renderable->GetTexture();

	// U::Texture::Iterator& it = texture.Begin();
	// const U::Texture::Iterator& end = texture.End();

	for (auto it = texture.CBegin(); it != texture.CEnd(); ++it)
	{
		int x = renderable->GetX() + it.GetX();
		int y = renderable->GetY() + it.GetY();

		/* Check if pixel is out of output borders*/
		if (x < 0 || x > output.GetWidth() || y < 0 || y > output.GetHeight())
		{
			continue;
		}
		else
		{
			output.GetPixel(x, y) = *it;
		}
	} 	
}

// void U::Render::RenderInto(U::Buffer& buffer)
// {
// 	int depth = buffer.GetDepth() / 8;
// 
// 	int height = buffer.GetHeight();
// 	int width = buffer.GetWidth();
// 
// 	char* data = buffer.GetData();
// 
// 	/* Test */
// 	for (int y = 0; y < height; y++)
// 	{
// 		for (int x = 0; x < width; x++)
// 		{
// 			data[(y * width + x) * depth] = 255 * (float)x / (float)width; /* Blue */
// 			data[(y * width + x) * depth + 1] = 255 * (float)x / (float)width; /* Red */
// 			data[(y * width + x) * depth + 2] = 255 * (float)y / (float)height; /* Green */
// 			data[(y * width + x) * depth + 3] = 255; /* Alpha */
// 		}
// 	}
// }
