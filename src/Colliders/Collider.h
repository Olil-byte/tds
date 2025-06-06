#ifndef COLLIDER_H
#define COLLIDER_H

#include "Math.hpp"

namespace U
{
    class ICollider
    {
    public:
	    virtual ~ICollider() = default;

        virtual bool IsStatic() = 0;
    };

    class AABB: public ICollider
    {
    public:
	    AABB(float x, float y, float w, float h, bool isStatic = false) 
	    {
	    	m_x = x;
		    m_y = y;
		    m_w = w;
		    m_h = h;

            m_isStatic = isStatic;
	    }
	    /* Projections on axises */
	    float GetX1() { return m_x - m_w / 2; }
	    float GetX2() { return m_x + m_w / 2; }
	    float GetY1() { return m_y - m_h / 2; }
	    float GetY2() { return m_y + m_h / 2;}

        float GetX() { return m_x; }
	    void SetX(float value) { m_x = value; }
        float GetY() { return m_y; }
	    void SetY(float value) { m_y = value; }

        bool IsStatic() { return m_isStatic; }
	
private:
	/* Coords of center */
	float m_x;
	float m_y;
	
	float m_w;
	float m_h;

    bool m_isStatic;
};
};

#endif