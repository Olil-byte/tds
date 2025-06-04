#include "Texture.h"

/* Texture class implementation */

U::Texture::Texture(unsigned int width, unsigned int height)
{
	m_width = width;
	m_height = height;
	
	m_data = new Pixel[width * height];
}

U::Texture::~Texture()
{
	delete[] m_data;
}

/* TextureIterator class implementation */

U::Texture::Iterator::Iterator(U::Texture* texture, unsigned int x, unsigned int y)
{
	m_texture = texture;

	m_x = x;
	m_y = y;
}

U::Texture::Iterator::Iterator(const U::Texture* texture, unsigned int x, unsigned int y)
{
	m_texture = (U::Texture*)texture; // bad hack, sorry :(

	m_x = x;
	m_y = y;
}

U::Pixel& U::Texture::Iterator::operator*()
{
	return m_texture->GetPixel(m_x, m_y);
}

const U::Pixel& U::Texture::Iterator::operator*() const
{
	return m_texture->GetPixel(m_x, m_y);
}

U::Pixel* U::Texture::Iterator::operator->()
{
	return &m_texture->GetPixel(m_x, m_y);
}

const U::Pixel* U::Texture::Iterator::operator->() const
{
	return &m_texture->GetPixel(m_x, m_y);
} 

U::Texture::Iterator& U::Texture::Iterator::operator++()
{
	if (m_x < m_texture->GetWidth())
	{
		++m_x;	
	}
	else
	{
		m_x = 0;
		++m_y;
	}

	return *this;
}

const U::Texture::Iterator& U::Texture::Iterator::operator++() const
{
	if (m_x < m_texture->GetWidth())
	{
		++m_x;	
	}
	else
	{
		m_x = 0;
		++m_y;
	}

	return *this;
}

bool U::Texture::Iterator::operator==(const U::Texture::Iterator& other) const
{
	return (m_texture == other.m_texture && m_x == other.m_x && m_y == other.m_y);
}

bool U::Texture::Iterator::operator!=(const U::Texture::Iterator& other) const
{
	return (m_texture != other.m_texture || m_x != other.m_x || m_y != other.m_y);
}

