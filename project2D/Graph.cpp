#include "Graph.h"
#include <Font.h>
#include <assert.h>


namespace Pathfinding {

	Graph::Graph()
	{
	}


	Graph::~Graph()
	{
		if (m_font != nullptr)
			delete m_font;
	}
	
	void Graph::addVertex(const Vertex& v)
	{
		m_vertices.push_back(new Vertex (v));
	}

	void Graph::addVertex(float x, float y, string id)
	{
		m_vertices.push_back(new Vertex(Vector2(x, y), id));
	}

	Vertex* Graph::getVertex(string id)
	{
		for (int i = 0; i < m_vertices.size(); i++)
		{
			if (m_vertices[i]->m_ID == id)
				return m_vertices[i];
		}
		return nullptr;
	}

	void Graph::addEdge(string vertexFromID, string vertexToID, float cost, bool twoWay)
	{
		Vertex* vertexFrom = getVertex(vertexFromID);
		Vertex* vertexTo = getVertex(vertexToID);

		assert(vertexFrom != nullptr);
		assert(vertexTo != nullptr);

		Edge* edge = new Edge(vertexTo, cost);
		
		m_edges.push_back(edge);
		vertexFrom->m_edges.push_back(edge);

		if (twoWay) 
		{

			edge = new Edge(vertexFrom, cost);
			vertexTo->m_edges.push_back(edge);
			m_edges.push_back(edge);
		}
	}

	void Graph::addEdge(Vertex* vertexFrom, Vertex* vertexTo, float cost, bool twoWay)
	{
		assert(vertexFrom != nullptr);
		assert(vertexTo != nullptr);

		Edge* edge = new Edge(vertexTo, cost);

		m_edges.push_back(edge);
		vertexFrom->m_edges.push_back(edge);

		if (twoWay)
		{

			edge = new Edge(vertexFrom, cost);
			vertexTo->m_edges.push_back(edge);
			m_edges.push_back(edge);
		}

	}

	void Graph::clear()
	{
		m_vertices.clear();
	}

	Vertex* Graph::operator[](int index)
	{
		return m_vertices[index];
	}

	unsigned int Graph::size()
	{
		return m_vertices.size();
	}

	void Graph::drawGraph(aie::Renderer2D * renderer)
	{
		if (m_font == nullptr)
			m_font = new aie::Font("./font/consolas.ttf", 20);

		renderer->setRenderColour(0, 0, 1);

		for (int i = 0; i < m_vertices.size(); i++)
		{
			for (int j = 0; j < m_vertices[i]->m_edges.size(); j++)
			{
				renderer->drawLine(m_vertices[i]->m_position.x, m_vertices[i]->m_position.y, m_vertices[i]->m_edges[j]->m_target->m_position.x, m_vertices[i]->m_edges[j]->m_target->m_position.y);
			}
		}

		for (int i = 0; i < m_vertices.size(); i++)
		{
			renderer->drawCircle(m_vertices[i]->m_position.x, m_vertices[i]->m_position.y, 10, 0);
		}

		renderer->setRenderColour(1, 1, 1);

		for (int i = 0; i < m_vertices.size(); i++)
		{
			renderer->drawText(m_font, m_vertices[i]->m_ID.c_str(), m_vertices[i]->m_position.x-5, m_vertices[i]->m_position.y-5);
		}

	}

	void Graph::connectNearby(float value)
	{
		for (Vertex* v1 : m_vertices) 
		{
			for (Vertex* v2 : m_vertices) 
			{
				if (v1 == v2)
				{
					continue;

				}

				float distance = v1->m_position.distance(v2->m_position);
				if (distance <= value)
				{
					addEdge(v1, v2, distance);
				}

			}

		}
	}
	
}

