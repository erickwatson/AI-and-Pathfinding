#pragma once
#include "GameObject.h"
#include "FollowBehaviour.h"
#include "Application.h"
#include "Renderer2D.h"
#include "KeyboardBehaviour.h"

class Application2D : public aie::Application {
public:

	Application2D();
	virtual ~Application2D();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

protected:

	aie::Renderer2D*	m_2dRenderer;
	aie::Font*			m_font;

	GameObject m_player;
	KeyboardBehaviour m_commandInput;

	GameObject m_enemy;
	FollowBehaviour m_followBehaviour;

	float m_cameraX, m_cameraY;
	float m_timer;
};