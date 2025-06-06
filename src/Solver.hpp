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
	bool IsCollideAABBandAABB(GameObject* objectA, GameObject* objectB)
	{
		AABB* a = (AABB*)objectA->GetCollider();
		AABB* b = (AABB*)objectB->GetCollider();
	
		bool isCollides = (a->GetX1() <= b->GetX1() && b->GetX1() <= a->GetX2() || 
		b->GetX1() <= a->GetX1() && a->GetX1() <= b->GetX2()) &&
		(a->GetY1() <= b->GetY1() && b->GetY1() <= a->GetY2() || 
		b->GetY1() <= a->GetY1() && a->GetY1() <= b->GetY2());

		return isCollides;
	}

	void AABBvsAABB(GameObject* objectA, GameObject* objectB, float dt)
	{
		bool isCollides = IsCollideAABBandAABB(objectA, objectB);
		if (isCollides)
		{
			SolveAABBvsAABB(objectA, objectB, dt);
		}
	}

	void SolveAABBvsAABB(GameObject* objectA, GameObject* objectB, float dt)
	{
		Vec2d* directionA = objectA->GetDirection();
		Vec2d* positionA = objectA->GetPosition();
		float* speedA = objectB->GetSpeed();

		AABB* a = (AABB*)objectA->GetCollider();

		positionA->x += -directionA->x * *speedA * dt;
		a->SetX(a->GetX() + -directionA->x * *speedA * dt);
		positionA->y += directionA->y * *speedA * dt;
		a->SetY(a->GetY() + directionA->y * *speedA * dt);
		if (IsCollideAABBandAABB(objectA, objectB))
		{
			positionA->x -= -directionA->x * *speedA * dt;
			a->SetX(a->GetX() - -directionA->x * *speedA * dt);
			positionA->y -= directionA->y * *speedA * dt;
			a->SetY(a->GetY() - directionA->y * *speedA * dt);
		}
		else
		{
			return;
		}
		positionA->x += directionA->x * *speedA * dt;
		a->SetX(a->GetX() + directionA->x * *speedA * dt);
		positionA->y += -directionA->y * *speedA * dt;
		a->SetY(a->GetY() - directionA->y * *speedA * dt);
		if (IsCollideAABBandAABB(objectA, objectB))
		{
			positionA->x -= directionA->x * *speedA * dt;
			a->SetX(a->GetX() - directionA->x * *speedA * dt);
			positionA->y -= -directionA->y * *speedA * dt;
			a->SetY(a->GetY() + directionA->y * *speedA * dt);
		}
		else
		{
			return;
		}
		positionA->x += -directionA->x * *speedA * dt;
		positionA->y += -directionA->y * *speedA * dt;
	};
};

};



#endif
