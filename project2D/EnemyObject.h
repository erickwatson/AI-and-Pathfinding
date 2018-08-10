#pragma once
#include "GameObject.h"
#include <list>
#include "Graph.h"

class EnemyObject : public GameObject
{
public:

	EnemyObject(Pathfinding::Graph*);

	//EnemyObject();

	~EnemyObject();

	void draw(aie::Renderer2D*)override;

protected:

	Pathfinding::Graph*					m_enemyGraph;
	std::list <Pathfinding::Vertex*>	m_path;

};

