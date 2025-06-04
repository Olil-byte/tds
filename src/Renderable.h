#ifndef RENDERABLE_H
#define RENDERABLE_H

#include "Texture.h"

namespace U
{

class IRenderable
{
public:
	virtual ~IRenderable() = default;

	virtual int GetX() const = 0;
	virtual void SetX(int value) = 0;
	virtual int GetY() const = 0;
	virtual void SetY(int value) = 0;

	virtual U::Texture& GetTexture() = 0;
	virtual const U::Texture& GetTexture() const = 0;
};

class Square: public IRenderable
{
public:
	Square(int x, int y, int w, int h) : m_texture(w, h)
	{
		m_x = x;
		m_y = y;
		
		for (auto it = m_texture.Begin(); it != m_texture.End(); ++it)
		{
			it->r = 128;
			it->g = 128;
			it->b = 128;
			it->a = 255;
		}
	}

	int GetX() const override { return m_x; }
	void SetX(int value) override { m_x = value; }
	int GetY() const override { return m_y; }
	void SetY(int value) override { m_y = value; }

	U::Texture& GetTexture() override { return m_texture; }
	const U::Texture& GetTexture() const override { return m_texture; }

private:
	int m_x;
	int m_y;

	U::Texture m_texture;
};

};

#endif
