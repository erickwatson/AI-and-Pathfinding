#pragma once
#include "Vector2.h"
#include "Behaviour.h"
class KeyboardBehaviour : public Behaviour
{
	
public:
	KeyboardBehaviour();
	~KeyboardBehaviour();

	virtual eBehaviourResult execute(GameObject* gameObject, float deltaTime);


private:

	//virtual eBehaviourResult execute(GameObject* gameObject, float deltaTime);
};

