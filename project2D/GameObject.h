#pragma once
#include <vector>
#include "Behaviour.h"
#include "Vector2.h"
#include "Matrix3.h"
#include <vector>
#include "Graph.h"

class Behaviour;

class GameObject
{
public:
	GameObject();
	virtual ~GameObject();

	// Movement functions
	void setPosition(float x, float y) { m_position = Vector2(x, y); }
	void setAcceleration(float x, float y) { m_acceleration = Vector2(x, y); }
	void addAcceleration(float x, float y) { m_acceleration += Vector2(x, y); }
	void setVelocity(float x, float y) { m_velocity = Vector2(x, y); }
	void setDrag(float drag) { m_drag = drag; }

	void addForce(float x, float y) { m_force += Vector2(x, y); }

	void getPosition(float* x, float* y) const { *x = m_position.x; *y = m_position.y; }
	Vector2 getPosition()const { return (m_position); }
	void translate(float x, float y) { m_position.x += x; m_position.y += y; }

	// Add a behaviour
	void addBehaviour(Behaviour* behaviour);
	//void translate(float x, float y);
	void rotate(float radians);
	
	// Update game object and execute behaviours
	virtual void update(float deltaTime);

	virtual void draw(aie::Renderer2D*);


	void setSpeed(float speed) {
		m_setSpeed = speed;
	};


protected:

	Pathfinding::Graph m_pathGraph;

	Vector2 m_position;
	Vector2 m_acceleration;
	Vector2 m_velocity;
	Vector2 m_force;

	float m_maxVelocity;
	float m_maxForce;
	float m_drag;

	float m_setSpeed;

	std::vector<Behaviour*> m_behaviours;

	Matrix3 m_localTransform = Matrix3::identity;
	Matrix3 m_globalTransform = Matrix3::identity;

};

