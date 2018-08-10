#include "Application2D.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include "GameObject.h"

Application2D::Application2D():m_enemy(&m_graph) {

}

Application2D::~Application2D() {

}

bool Application2D::startup() {
	
	m_2dRenderer = new aie::Renderer2D();
	m_font = new aie::Font("./font/consolas.ttf", 32);

	createGraph();

	m_playerBehaviour.setSpeed(400);
	m_player.addBehaviour(&m_playerBehaviour);
	m_player.setPosition(getWindowWidth() * 0.5f, getWindowHeight() * 0.5f);

	m_enemy.addBehaviour(&m_enemyBehaviour);
	m_enemy.setPosition(100, 100);

	//m_followBehaviour.setSpeed(100);
	//m_followBehaviour.setTarget(&m_player);
	//m_player.addBehaviour(&m_playerFollowBehaviour);
	


	// created new states
	auto attackState = new AttackState(&m_player, &m_graph, 150);
	auto pathAttackState = new PathAttackState(&m_player, &m_graph, 150);
	auto searchState = new SearchState();
	auto idleState = new IdleState();

	// create the condition, setting the player as the target
	auto withinRangeCondition = new WithinRangeCondition(&m_player, 200);
	auto notWithinRangeCondition = new NotWithinRangeCondition(&m_player, 300);

	// create the transition, this will transition to the attack state when the 
	// withinRange condition is met 
	auto toAttackTransition = new Transition(attackState, withinRangeCondition);
	// add the transition to the idle state
	idleState->addTransition(toAttackTransition);

	//auto notWithinRangeCondition = new NotWithinRangeCondition(&m_player, 200);
	
	auto toIdleTransition = new Transition(idleState, notWithinRangeCondition);
	attackState->addTransition(toIdleTransition);


	// add all the states, conditions and transitions to the FSM enemy behaviour
	m_enemyBehaviour.addState(attackState);
	m_enemyBehaviour.addState(idleState);

	m_enemyBehaviour.addCondition(withinRangeCondition);
	m_enemyBehaviour.addTransition(toAttackTransition);

	// set the current state of the FSM
	m_enemyBehaviour.setCurrentState(idleState);
	
	
	return true;
}

void Application2D::shutdown() {
	
	delete m_font;

	delete m_2dRenderer;
}

void Application2D::update(float deltaTime) {

	//m_timer += deltaTime;

	m_player.update(deltaTime);
	m_enemy.update(deltaTime);

	
	


	// input example
	aie::Input* input = aie::Input::getInstance();
	/*
	 // Move camera
	// use arrow keys to move camera
	if (input->isKeyDown(aie::INPUT_KEY_UP))
		m_cameraY += 500.0f * deltaTime;

	if (input->isKeyDown(aie::INPUT_KEY_DOWN))
		m_cameraY -= 500.0f * deltaTime;

	if (input->isKeyDown(aie::INPUT_KEY_LEFT))
		m_cameraX -= 500.0f * deltaTime;

	if (input->isKeyDown(aie::INPUT_KEY_RIGHT))
		m_cameraX += 500.0f * deltaTime;
	*/

	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
}

void Application2D::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_2dRenderer->begin();

	// Ask the graph to draw vertices/edges
	m_graph.drawGraph(m_2dRenderer);

	float x = 0, y = 0;

	// Draw Player as a green circle
	m_player.draw(m_2dRenderer);

	// Draw Player as a red circle
	m_enemy.draw(m_2dRenderer);

	// set the camera position before we begin rendering
	//m_2dRenderer->setCameraPos(m_cameraX, m_cameraY);
	
	// output some text, uses the last used colour
	char fps[32];
	sprintf_s(fps, 32, "FPS: %i", getFPS());
	m_2dRenderer->drawText(m_font, fps, 0, 720 - 32);
	m_2dRenderer->drawText(m_font, "Press ESC to quit!", 0, 720 - 64);

	system("CLS");
	
	// done drawing sprites
	m_2dRenderer->end();
}

void Application2D::createGraph()
{

	m_graph.clear();
	int width = getWindowWidth();
	int height = getWindowHeight();
	int spacing = 80;
	int gridY = 300;
	int gridX = 600;
	int distance = 130;

	// x * y grid in the middle of screen
	int nodeID = 0;
	for (unsigned int y = height / 2 - gridY; y <= height / 2 + gridY; y += spacing)
	{
		for (unsigned int x = width / 2 - gridX; x <= width / 2 + gridX; x += spacing)
		{
			m_graph.addVertex(x, y, std::to_string(nodeID));
			nodeID++;
		}
	
	}

	m_graph.connectNearby(distance);



	//m_graph.addVertex(210, 50, "a");
	//m_graph.addVertex(150, 100, "b");
	//m_graph.addVertex(250, 150, "c");
	//m_graph.addVertex(200, 200, "d");
	//m_graph.addEdge("a", "c", 2);
	//m_graph.addEdge("a", "d", 2);


}