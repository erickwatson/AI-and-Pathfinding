#pragma once
#include "Behaviour.h"
#include "State.h"
#include "Transition.h"


using namespace std;

class State;
class Transition;
class Condition;

class FSM : public Behaviour
{
public:
	FSM() : m_currentState(nullptr) {}

	virtual ~FSM() {
		for (auto state : m_states)
			delete state;
		for (auto t : m_transitions)
			delete t;
		for (auto c : m_conditions)
			delete c;
	}

	// Add components, take owenership, usurp the proleteriat
	State* addState(State* state) 
	{ 
		m_states.push_back(state); return state; 
	}

	Transition* addTransition(Transition* transition) 
	{
		m_transitions.push_back(transition); return transition;
	}

	Condition* addCondition(Condition* condition)
	{
		m_conditions.push_back(condition); return condition;
	}

	void setCurrentState(State* state) { m_currentState = state;  }

	virtual eBehaviourResult execute(GameObject* gameObject, float deltaTime);

protected:

	vector<State*>			m_states;
	vector<Transition*>		m_transitions;
	vector<Condition*>		m_conditions;

	State*					m_currentState;

};

