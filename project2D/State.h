#pragma once
#include <vector>
#include "Graph.h"
#include <list>

using namespace std;
using namespace Pathfinding;

class GameObject;
class Transition;

class State
{
public:
	State();
	virtual ~State() {}

	virtual void update(GameObject* agent, float deltaTime) = 0;
	virtual void init(GameObject* agent) {};
	
	virtual void exit(GameObject* agent) {};

	void addTransition(Transition* transition) {
		m_transitions.push_back(transition);
	}

	Transition* getTriggeredTransition(GameObject* gameObject);

protected:
	vector<Transition*> m_transitions;
 
};


// Doin nothin
class IdleState : public State {
public:
	IdleState() {}
	virtual ~IdleState() {}

	virtual void update(GameObject* gameObject, float deltaTime);
};

class AttackState : public State {
public:
	AttackState(GameObject* target, Graph* graph, float speed) : m_target(target), m_speed(speed), m_graph(graph) {}
	virtual ~AttackState() {}
	void update(GameObject* gameObject, float deltaTime) override;
	void init(GameObject* agent) override;

private:
	float			m_speed;
	GameObject*		m_target;
	Graph*			m_graph;

	std::list <Vertex*>	m_path;

};

/*
class PathAttackState : public State {
public:
	PathAttackState(GameObject* target, Graph* graph, float speed) : m_target(target), m_speed(speed), m_graph(graph) {}
	virtual ~PathAttackState() {}
	void update(GameObject* gameObject, float deltaTime) override;
	void init(GameObject* agent) override;

private:
	float			m_speed;
	GameObject*		m_target;
	Graph*			m_graph;

	std::list <Vertex*>	m_path;

};
*/


class SearchState : public State {
public:
	SearchState() {}
	virtual ~SearchState() {}

	virtual void update(GameObject* gameObject, float deltaTime);
};