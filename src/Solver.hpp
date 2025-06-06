#ifndef SOLVER_H
#define SOLVER_H

#include "GameObject.h"
#include <stdio.h>

namespace U
{

class ICollider
{
public:
	virtual ~ICollider() = default;
};

class AABB: public ICollider
{
public:
	AABB(float x, float y, float w, float h) 
	{
		m_x = x;
		m_y = y;
		m_w = w;
		m_h = h;
	}
	/* Projections on axises */
	float GetX1() { return m_x - m_w / 2; }
	float GetX2() { return m_x + m_w / 2; }
	float GetY1() { return m_y - m_h / 2; }
	float GetY2() { return m_y + m_h / 2;}

	void SetX(float value) { m_x = value; }
	void SetY(float value) { m_y = value; }
	
private:
	/* Coords of center */
	float m_x;
	float m_y;
	
	float m_w;
	float m_h;
};

};



#endif
