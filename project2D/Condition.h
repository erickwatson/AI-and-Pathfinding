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

class WithinRangeCondition : public Condition {
public: 
	WithinRangeCondition(const GameObject* target, float range)
		: m_target(target), m_range(range) {}
	virtual ~WithinRangeCondition() {}

	virtual bool test(GameObject* gameObject) const {
		// get target position
		float tx = 0, ty = 0;
		gameObject->getPosition(&tx, &ty);

		// get my pos
		float x = 0, y = 0;
		gameObject->getPosition(&x, &y);

		// compare and measure
		float xDiff = tx - x;
		float yDiff = ty - y;
		float distance = sqrtf(xDiff * xDiff + yDiff * yDiff);

		return distance <= m_range;
	}
	
private:
	const GameObject* m_target;
	float m_range;

};