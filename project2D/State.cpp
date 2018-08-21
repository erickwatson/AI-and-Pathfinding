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
	
	// If we have no path, set a new one to a random point
	if (gameObject->GetPath().empty())
	{
		int index = rand() % m_graph->getSize();
		gameObject->SetPath(nullptr, (*m_graph)[index], m_graph);
		std::cout << "Index: " << index <<  std::endl;
	}

	// follow the path frame by frame
	gameObject->FollowPath(deltaTime);
}

void IdleState::exit(GameObject* gameObject) {
	gameObject->GetPath().clear();
	// When the enemy changes state we clear it's destination path
	// when it tries to find a path again it will find a new one

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
	
		// if the player has moved too far from the end of our FSM's path
		if (m_distance ) {
			// PUT CODE HERE AYE
			// Gotta use this stuff
			//std::list<Vertex*> path;
			//Pathfinding::AStar(m_graph[20], m_graph[84], path);



		}
		//     recalculate a path to the player from our closest current node

		// step along the agent's path using FSM::FollowPath
}

/*
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
*/

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
