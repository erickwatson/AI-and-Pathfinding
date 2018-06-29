#include "GameObject.h"



GameObject::GameObject()
{
	m_acceleration = { 0,0 };
	m_velocity = { 0,0 };
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

	m_position += m_velocity * deltaTime;

	// Force
	m_velocity -= 1.0f * m_velocity * deltaTime;
}

void GameObject::rotate(float radians) {
	m_localTransform.rotateZ(radians);
}

