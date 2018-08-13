#include "GameObject.h"
#include <iostream>


GameObject::GameObject()
{
	m_acceleration = { 0,0 };
	m_velocity = { 0,0 };
	//m_maxVelocity = 200;
	//m_maxForce = 20;
	m_drag = 0.03f;
}


GameObject::~GameObject()
{
}

void GameObject::addBehaviour(Behaviour * behaviour)
{
	m_behaviours.push_back(behaviour);
}

void GameObject::update(float deltaTime) {
	for (auto behaviour : m_behaviours)
		behaviour->execute(this, deltaTime);


	m_velocity += m_acceleration * deltaTime;
	//	m_velocity += m_force * deltaTime;

	m_position += m_velocity * deltaTime;

	// Damping/drag
	m_velocity = m_velocity * (1.0f - m_drag);

	std::cout << "Velocity: " << m_velocity.x << "," << m_velocity.y << std::endl;

	

	// Reset the acceleration
	m_acceleration = { 0, 0 };

}

void GameObject::rotate(float radians) {
	m_localTransform.rotateZ(radians);
}


void GameObject::draw(aie::Renderer2D* renderer)
{
	float x, y;
	getPosition(&x, &y);
	renderer->setRenderColour(0, 1, 0);
	renderer->drawCircle(x, y, 10);
}