#include "EnemyObject.h"
#include "FSM.h"


EnemyObject::EnemyObject(Pathfinding::Graph* graph)
{
	m_enemyGraph = graph;
}


EnemyObject::~EnemyObject()
{
}

void EnemyObject::draw(aie::Renderer2D* renderer)
{
	float x, y;
	getPosition(&x, &y);
	renderer->setRenderColour(1, 0, 0);
	renderer->drawCircle(x, y, 10);
}