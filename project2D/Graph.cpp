#include "Graph.h"

namespace Pathfinding {

	Graph::Graph()
	{
	}


	Graph::~Graph()
	{
	}
	
	void Graph::addVertex(const Vertex& v)
	{
		m_vertices.push_back(v);
	}

	void Graph::addVertex(float x, float y)
	{
		m_vertices.push_back(Vector2(x, y));
	}

	void Graph::clear()
	{
		m_vertices.clear();
	}

	Vertex& Graph::operator[](int index)
	{
		return m_vertices[index];
	}

	unsigned int Graph::size()
	{
		return m_vertices.size();
	}

}