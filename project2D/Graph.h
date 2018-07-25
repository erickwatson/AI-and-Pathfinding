#pragma once
#include <vector>
#include "Vector2.h"


namespace Pathfinding
{
	class Vertex;

	// define and edge / link
	class Edge {
	public:

		Edge(Vertex* t = nullptr, float userdata = 0)
			:	m_cost(userdata),
				m_target(t)
		{}
		virtual ~Edge() {}

		// the target vertex
		Vertex* m_target;

		// custom user data (alternative to deriving)
		//void* m_userData;
		float m_cost;
	};

	class Vertex {
	public: 

		Vertex(const Vector2& pos, Vertex* userdata = nullptr)
			:	m_position(pos),
				m_parent(userdata),
				m_gScore(FLT_MAX)
		{}

		virtual ~Vertex() {}

		// list of edges
		std::vector<Edge*> m_edges;

		// custom user data (alternative to deriving)
		Vertex* m_parent;

		// The vertex position
		Vector2 m_position;

		float m_gScore;
		float m_hScore;
		float m_fScore;
	};
	
	class Graph
	{
	public:
		Graph();
		
		~Graph();
		
		void addVertex(const Vertex& v);

		void addVertex(float x, float y);
	
		void clear();

		Vertex& operator[](int index);

		unsigned int size();

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