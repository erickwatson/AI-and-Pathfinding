#include "FollowBehaviour.h"



FollowBehaviour::FollowBehaviour()
{
	m_speed = 10;
}


FollowBehaviour::~FollowBehaviour()
{
}

eBehaviourResult FollowBehaviour::execute(GameObject* gameObject, float deltaTime) {
	if (m_target == nullptr)
	{
		return eBehaviourResult::FAILURE;
	}

	Vector2 position = gameObject->getPosition();
	Vector2 targetPosition = m_target->getPosition();

	// Calculate distance and return float m_distance().
	float m_distance = position.distance(targetPosition);

	

	if (m_distance > 0)
	{
		// Get the vector describing the direction of the target and normalise it
		Vector2 direction = (targetPosition - position);
		direction.normalise();

		// Move this agent in this direction at the agent's maximum speed
		gameObject->translate((direction.x * m_speed) * deltaTime, (direction.y * m_speed) * deltaTime);
	}

	return eBehaviourResult::SUCCESS;
}