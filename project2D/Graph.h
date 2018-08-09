#pragma once
#include <vector>
#include "Vector2.h"
#include <Renderer2D.h>


using namespace std;


namespace Pathfinding
{
	class Vertex;

	// define and edge / link
	class Edge {
	public:

		Edge(Vertex* t = nullptr, float cost = 0)
			:	m_cost(cost),
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

		Vertex(const Vector2& pos, string id, Vertex* parent = nullptr)
			:	m_position(pos),
				m_parent(parent),
				m_gScore(FLT_MAX),
				m_ID(id)
		{}

		virtual ~Vertex() {}

		// list of edges
		std::vector<Edge*> m_edges;

		// custom user data (alternative to deriving)
		Vertex* m_parent;

		// The vertex position
		Vector2 m_position;

		string m_ID;

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

		void addVertex(float x, float y, string id);
		
		Vertex* getVertex(string id);

		void addEdge(string vertexFromID, string vertexToID, float cost, bool twoWay = true);
		void addEdge(Vertex* vertexFrom, Vertex* vertexTo, float cost, bool twoWay = true);

		void clear();

		Vertex* operator[](int index);

		unsigned int size();

		void drawGraph(aie::Renderer2D* renderer);

		void connectNearby(float value);

		aie::Font* m_font = nullptr;

	protected:
		std::vector<Vertex*> m_vertices;
		std::vector<Edge*> m_edges;


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



