#pragma once
#include <vector>

using namespace std;

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

	virtual void update(GameObject* gameObject, float deltaTime) {}
};

class AttackState : public State {
public:
	AttackState(GameObject* target, float speed) : m_target(target), m_speed(speed) {}
	virtual ~AttackState() {}
	virtual void update(GameObject* gameObject, float deltaTime);

private:
	float		m_speed;
	GameObject* m_target;

};