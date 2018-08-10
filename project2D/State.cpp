#include "State.h"
#include "Transition.h"


State::State()
{
}


 //State::~State()
//{
//}

Transition* State::getTriggeredTransition(GameObject* gameObject) {
	for (auto transition : m_transitions) {
		if (transition->hasTriggered(gameObject))
			return transition;
	}
	return nullptr;
}

void IdleState::update(GameObject * gameObject, float deltaTime)
{

}

void AttackState::update(GameObject * gameObject, float deltaTime)
{
	if (m_target == nullptr)
	{
		return;
	}

	Vector2 position = gameObject->getPosition();
	Vector2 targetPosition = m_target->getPosition();

	// Calculate distance and return float m_distance().
	float m_distance = position.distance(targetPosition);

		if (m_distance > 0) {
			// Get the vector describing the direction of the target and normalise it
			Vector2 direction = (targetPosition - position);
			direction.normalise();

			// Move this agent in this direction at the agent's maximum speed
			gameObject->translate((direction.x * m_speed) * deltaTime, (direction.y * m_speed) * deltaTime);
		}
	
}

void PathAttackState::update(GameObject * gameObject, float deltaTime)
{
	if (m_target == nullptr)
	{
		return;
	}

	Vector2 position = gameObject->getPosition();
	Vector2 targetPosition = m_target->getPosition();

	// Calculate distance and return float m_distance().
	float m_distance = position.distance(targetPosition);

	if (m_distance > 0) {
		// Get the vector describing the direction of the target and normalise it
		Vector2 direction = (targetPosition - position);
		direction.normalise();

		// Move this agent in this direction at the agent's maximum speed
		gameObject->translate((direction.x * m_speed) * deltaTime, (direction.y * m_speed) * deltaTime);
	}

}

void AttackState::init(GameObject * agent)
{
	if (m_target != nullptr)
	{
		Vertex* startNode = m_graph->getClosestVertex(agent->getPosition());
		Vertex* endNode = m_graph->getClosestVertex(m_target->getPosition());

		AStar(startNode, endNode, m_path);
	
	}


}

void SearchState::update(GameObject * gameObject, float deltaTime)
{

}
