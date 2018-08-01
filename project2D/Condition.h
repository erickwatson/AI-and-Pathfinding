#pragma once
#include "Behaviour.h"

class Condition : public Behaviour
{
public:
	Condition() {}
	virtual ~Condition() {}

	virtual bool test(GameObject* gameObject) const = 0;

	virtual eBehaviourResult execute(GameObject* gameObject, float deltaTime) {
		if (test(gameObject))
			return eBehaviourResult::SUCCESS;
		return eBehaviourResult::FAILURE;
	}
};

