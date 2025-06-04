#ifndef TEXTURE_H
#define TEXTURE_H

namespace U
{

struct Pixel
{
	char r;
	char g;
	char b;
	char a;
};

class Texture
{
public:
	Texture(unsigned int width, unsigned int height);
	~Texture();

	Texture(const Texture& other) = delete;
	Texture& operator=(const Texture& other) = delete;

	inline unsigned int GetWidth() const { return m_width; }
	inline unsigned int GetHeight() const { return m_height; }

	inline Pixel& GetPixel(unsigned int x, unsigned int y) { return m_data[y * m_width + x]; }
	inline const Pixel& GetPixel(unsigned int x, unsigned int y) { return m_data[y * m_width + x]; }

	inline Pixel* GetData() { return m_data; } 

	friend Texture::Iterator;
	class Iterator
	{
	public:
		Iterator() = delete;
		Iterator(Texture* texture);
		Iterator(Texture* texture, unsigned int x, unsigned int y);

		inline unsigned int GetX() const { return m_x; }
		inline unsigned int GetY() const { return m_y; }
		
		Pixel& operator*();
		const Pixel& operator*() const;
		
		Iterator& operator++();
		
	private:
		Texture* m_texture;
		
		/* For current position */
		unsigned int m_x;
		unsigned int m_y;
	};

	inline Iterator& Begin() { return Iterator(this); }
	inline const Iterator& End() { return Itetator(this, 0, m_height); }
	
private:
	unsigned int m_width;
	unsigned int m_height;
	
	Pixel* m_data;	
};

};

#endif
