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

	Transition* getTriggeredTrasition(GameObject* gameObject);

protected:
	vector<Transition*> m_transitions;
 
};

