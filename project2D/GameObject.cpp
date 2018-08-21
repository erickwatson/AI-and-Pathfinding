#include "GameObject.h"
#include <iostream>
#include "Graph.h"

using namespace Pathfinding;

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

	// std::cout << "Velocity: " << m_velocity.x << "," << m_velocity.y << std::endl;

	

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

void GameObject::FollowPath(float deltaTime) {

	if (m_path.empty())
		return;

	float speed = 100.0f; // TODO 

						  // get the nth element of the list
	auto iter = m_path.begin();
	std::advance(iter, m_currentNode);
	Vertex* vert = *iter;

	Vector2 target = vert->m_position;
	Vector2 direction = target - getPosition();
	float distance = direction.magnitude();
	if (distance < 1.0f) {
		// move to the next node
		m_currentNode++;
		if (m_currentNode >= m_path.size()) {
			m_path.clear();
		}
	}
	else {
		// move towards the target node
		Vector2 newPos = getPosition() + speed * deltaTime * direction * (1.0f / distance);
		setPosition(newPos.x, newPos.y);
	}
}

void GameObject::SetPath(Vertex* start, Vertex* end, Pathfinding::Graph* graph)
{
	// if we dont specify a start point, pick the closest node to us
	if (start == nullptr)
	{
		start = graph->getClosestVertex(m_position);
	}

	Pathfinding::AStar(start, end, m_path);
	m_currentNode = 0;
}