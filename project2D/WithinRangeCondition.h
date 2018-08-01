#pragma once
#include "Condition.h"

class WithinRangeCondition : public Condition {

public:
	WithinRangeCondition(const GameObject* target, float range) : m_target(target),
																m_range(range) {}
	virtual ~WithinRangeCondition()

	virtual bool test(GameObject* gameObject) const;

private:

	const GameObject* m_target;
	float m_range;

};

