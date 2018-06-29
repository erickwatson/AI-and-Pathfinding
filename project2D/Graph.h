#pragma once
#include <vector>
#include "Vector2.h"


namespace Graph
{
	class Vertex;

	// define and edge / link
	class Edge {
	public:

		Edge(Vertex* t = nullptr) : target(t) {}
		virtual ~Edge() {}

		// the target vertex
		Vertex* target;

		// custom user data (alternative to deriving)
		void* userData = nullptr;
	};

	class Vertex {
	public: 

		Vertex() {}
		virtual ~Vertex() {}

		// list of edges
		std::vector<Edge*> edges;

		// custom user data (alternative to deriving)
		void* userData = nullptr;
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