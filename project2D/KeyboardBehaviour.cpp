#include "KeyboardBehaviour.h"
#include "Input.h"
#include "GameObject.h"

KeyboardBehaviour::KeyboardBehaviour()
{
}


KeyboardBehaviour::~KeyboardBehaviour()
{
}

eBehaviourResult KeyboardBehaviour::execute(GameObject* gameObject, float deltaTime) {
	// input example
	aie::Input* input = aie::Input::getInstance();
	
	Vector2 accel = { 0,0 };

	float speed = m_setSpeed;


	// Move tank, the 100 magic-number represents speed
	if (input->isKeyDown(aie::INPUT_KEY_W)) {
		accel += {0, 1};
	

	}
	if (input->isKeyDown(aie::INPUT_KEY_S)) {
		accel += {0, -1};
	}

	// Move tank, the 100 magic-number represents speed
	if (input->isKeyDown(aie::INPUT_KEY_A)) {
		accel += {-1, 0};

	}
	if (input->isKeyDown(aie::INPUT_KEY_D)) {
		accel += {1, 0};
	}

	if (accel.magnitudeSqr() > 1)
		accel = accel.normalised();

	if (accel != Vector2(0,0))
		gameObject->setAcceleration(accel.x * speed, accel.y * speed);



	return eBehaviourResult::SUCCESS;
}