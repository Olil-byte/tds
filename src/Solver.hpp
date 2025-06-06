#ifndef SOLVER_H
#define SOLVER_H

#include "Colliders/Collider.h"
#include "GameObject.h"
#include <stdio.h>

namespace U
{

class Solver
{
public:
	void AABBvsAABB(GameObject* objectA, GameObject* objectB)
	{
		AABB* a = (AABB*)objectA->GetCollider();
		AABB* b = (AABB*)objectB->GetCollider();
	
		bool isCollides = (a->GetX1() <= b->GetX1() && b->GetX1() <= a->GetX2() || 
		b->GetX1() <= a->GetX1() && a->GetX1() <= b->GetX2()) &&
		(a->GetY1() <= b->GetY1() && b->GetY1() <= a->GetY2() || 
		b->GetY1() <= a->GetY1() && a->GetY1() <= b->GetY2());
		if (isCollides)
		{
			Vec2d* directionA = objectA->GetDirection();
			Vec2d* positionA = objectA->GetPosition();
			float* speedA = objectB->GetSpeed();
			directionA->x *= -1;
			directionA->y *= -1;

			positionA->x += directionA->x;
			positionA->y += directionA->y;
		}
	}
};

};



#endif
