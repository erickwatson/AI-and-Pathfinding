#include "FSM.h"


eBehaviourResult FSM::execute(GameObject* gameObject, float deltaTime) {

	if (m_currentState != nullptr) {
		Transition* transition = m_currentState->getTriggeredTransition(gameObject);

		if (transition != nullptr) {
			m_currentState->exit(gameObject);
			m_currentState = transition->getTargetState();
			m_currentState->init(gameObject);
		}

		m_currentState->update(gameObject, deltaTime);
		return eBehaviourResult::SUCCESS;

	}

	return eBehaviourResult::FAILURE;
}



 
// we need a member path
// and a int currentNodeIndex

// move towards path[currentNodeIndex]
// if we're close, increment the index unless wew've reached the end..