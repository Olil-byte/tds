#ifndef TEXTURE_H
#define TEXTURE_H

namespace U
{

union Texel
{
	struct 
	{
		char r;
		char g;
		char b;
		char a;	
	};
	unsigned int v;
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

	inline Texel& GetTexel(unsigned int x, unsigned int y) { return m_data[y * m_width + x]; }
	inline const Texel& GetPixel(unsigned int x, unsigned int y) const { return m_data[y * m_width + x]; }

	inline Texel* GetData() { return m_data; } 

	class Iterator
	{
	public:
		Iterator() = delete;
		Iterator(Texture* texture, unsigned int x = 0, unsigned int y = 0);
		Iterator(const Texture* texture, unsigned int x = 0, unsigned y = 0);

		inline unsigned int GetX() const { return m_x; }
		inline unsigned int GetY() const { return m_y; }
		
		Texel& operator*();
		const Texel& operator*() const;

		Texel* operator->();
		const Texel* operator->() const;
		
		Iterator& operator++();
		const Iterator& operator++() const;

		bool operator==(const Iterator& other) const;
		bool operator!=(const Iterator& other) const;
		
	private:
		Texture* m_texture;
		
		/* For current position */
		mutable unsigned int m_x;
		mutable unsigned int m_y;
	};
	friend Iterator;

	inline Iterator Begin() { return Iterator(this); }
	inline const Iterator CBegin() const { return Iterator(this); }
	inline const Iterator End() { return Iterator(this, 0, m_height); }
	inline const Iterator CEnd() const { return Iterator(this, 0, m_height); }
	
private:
	unsigned int m_width;
	unsigned int m_height;
	
	Texel* m_data;	
};

};

#endif
