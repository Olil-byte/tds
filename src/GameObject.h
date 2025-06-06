#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "Texture.h"

/* For Actor class */
#include "Keyboard.h"

#include <math.h>
#include <stdio.h>

#include "Solver.hpp"

namespace U
{

struct Vec2d
{
	float x;
	float y;
};

class IGameObject
{
public:
	virtual ~IGameObject() = default;

	virtual void Update(float dt) = 0;

	virtual const U::Texture& GetTexture() const = 0;

	virtual Vec2d& GetPosition() = 0;
	virtual const Vec2d& GetPosition() const = 0;

	virtual ICollider* GetCollider() { return nullptr; };
};

class Actor: public IGameObject
{
public:
	Actor(U::Keyboard* keyboard) : m_keyboard(keyboard), m_texture(50, 50), m_collider(1.0f, 1.0f, 50.0f, 50.0f)
	{
		for (auto it = m_texture.Begin(); it != m_texture.End(); ++it)
		{
			it->r = 255;
			it->g = 0;
			it->b = 0;
			it->a = 255;
		}
		
		m_position = { 1.0f, 1.0f };
		m_direction = { 0.0f, 0.0f };
		m_speed = 50.0f;
	}

	void Update(float dt) override
	{
		if (m_keyboard->IsKeyPressed(U::Key::W))
		{
			m_direction.y = 1.0f; 
		}
		if (m_keyboard->IsKeyPressed(U::Key::A))
		{
			m_direction.x = -1.0f;
		}
		if (m_keyboard->IsKeyPressed(U::Key::S))
		{
			m_direction.y = -1.0f;
		}
		if (m_keyboard->IsKeyPressed(U::Key::D))
		{
			m_direction.x = 1.0f;
		}

		float directionLength = sqrt(m_direction.x * m_direction.x + m_direction.y * m_direction.y);
		if (directionLength != 0.0f)
		{
			m_direction.x /= directionLength;
			m_direction.y /= directionLength;
		}

		m_position.x += m_direction.x * m_speed * dt;
		m_position.y += m_direction.y * m_speed * dt;

		m_direction = { 0.0f, 0.0f };

		m_collider.SetX(m_position.x);
		m_collider.SetY(m_position.y);
	}

	const U::Texture& GetTexture() const override { return m_texture; }

	Vec2d& GetPosition() override { return m_position; }
	const Vec2d& GetPosition() const override { return m_position; }

	ICollider* GetCollider() { return &m_collider; }

private:
	U::Keyboard* m_keyboard;
	U::Texture m_texture;
	
	Vec2d m_position;
	Vec2d m_direction;
	float m_speed;

	AABB m_collider;
};

class Wall: public IGameObject
{
public:
	Wall() : m_texture(50, 50), m_collider(1.0f, 1.0f, 50.0f, 50.0f)
	{
		for (auto it = m_texture.Begin(); it != m_texture.End(); ++it)
		{
			it->r = 0;
			it->g = 0;
			it->b = 0;
			it->a = 255;
		}
		
		m_position = { 1.0f, 1.0f };
		m_direction = { 0.0f, 0.0f };
		m_speed = 50.0f;
	}

	void Update(float dt) override
	{
	}

	const U::Texture& GetTexture() const override { return m_texture; }

	Vec2d& GetPosition() override { return m_position; }
	const Vec2d& GetPosition() const override { return m_position; }

	ICollider* GetCollider() { return &m_collider; }

private:
	U::Keyboard* m_keyboard;
	U::Texture m_texture;
	
	Vec2d m_position;
	Vec2d m_direction;
	float m_speed;

	AABB m_collider;
};

class Solver
{
public:
	void AABBvsAABB(IGameObject* objectA, IGameObject* objectB)
	{
		AABB* a = (AABB*)objectA->GetCollider();
		AABB* b = (AABB*)objectB->GetCollider();
	
		bool isCollides = (a->GetX1() <= b->GetX1() && b->GetX1() <= a->GetX2() || 
		b->GetX1() <= a->GetX1() && a->GetX1() <= b->GetX2()) &&
		(a->GetY1() <= b->GetY1() && b->GetY1() <= a->GetY2() || 
		b->GetY1() <= a->GetY1() && a->GetY1() <= b->GetY2());
		if (isCollides)
		{
			printf("Is Collides\n");
		}
	}
};

};

#endif
