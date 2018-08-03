#pragma once
#include "Vector2.h"
#include "Behaviour.h"
class KeyboardBehaviour : public Behaviour
{
	
public:
	KeyboardBehaviour();
	~KeyboardBehaviour();

	virtual eBehaviourResult execute(GameObject* gameObject, float deltaTime);

	void setSpeed(float speed) {
		m_setSpeed = speed;
	};

private:

	float m_setSpeed;

	//virtual eBehaviourResult execute(GameObject* gameObject, float deltaTime);
};

