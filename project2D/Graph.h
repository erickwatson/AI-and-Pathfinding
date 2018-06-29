#pragma once
#include <vector>
#include "Vector2.h"


namespace Pathfinding
{
	class Vertex;

	// define and edge / link
	class Edge {
	public:

		Edge(Vertex* t = nullptr, void* userdata = nullptr)
			:	m_userData(userdata),
				m_target(t)
		{}
		virtual ~Edge() {}

		// the target vertex
		Vertex* m_target;

		// custom user data (alternative to deriving)
		void* m_userData;
	};

	class Vertex {
	public: 

		Vertex(const Vector2& pos, void* userdata = nullptr)
			:	m_position(pos),
				m_userData(userdata)
		{}

		virtual ~Vertex() {}

		// list of edges
		std::vector<Edge*> m_edges;

		// custom user data (alternative to deriving)
		void* m_userData;

		// The vertex position
		Vector2 m_position;
	};
	
	class Graph
	{
	public:
		void addVertex(const Vertex& v)
		{
			m_vertices.push_back(v);
		}

		void addVertex(float x, float y)
		{
			m_vertices.push_back(Vector2(x, y));
		}

		void clear()
		{
			m_vertices.clear();
		}

		Vertex& operator[](int index) 
		{
			return m_vertices[index];
		}

		unsigned int size()
		{
			return m_vertices.size();
		}

	protected:
		std::vector<Vertex> m_vertices;
	};
}
/*
class Graph
{
public:
	Graph();
	~Graph();
	struct Node;

	struct Edge {
		Node* target;
		float cost;
	};

	struct Node {
		Vector2 postiion;

		float gscore;
		Node* parent;

		std::vector< Edge > connections;
	};

};
*/