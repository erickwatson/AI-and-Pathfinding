#include "Graph.h"
#include <list>
#include <algorithm>


namespace Pathfinding {

	bool compareVertexByGScore(Vertex* a, Vertex* b) {
		return (a->m_gScore < b->m_gScore);
	}

	bool compareVertexByFScore(Vertex* a, Vertex* b) {
		return (a->m_fScore < b->m_fScore);
	}

	bool AStar(Vertex* startNode, Vertex* endNode, std::list<Vertex*>& path)
	{
		if (startNode == nullptr || endNode == nullptr) {
			return false;
		}

		//Let openList be a List of Nodes
		std::list<Vertex*> openList;
		//Let closedList be a List of Nodes
		std::list<Vertex*> closedList;

		//Set startNode.parent to null
		startNode->m_parent = nullptr;
		//Set startNode.m_gscore to 0
		startNode->m_gScore = 0;

		//Add startNode to openList
		openList.push_back(startNode);

		Vertex* m_currentNode = nullptr;

		//While (openList != empty)
		while (!openList.empty())
		{
			//Sort openList by Node.gScore || openList.sort(Node.gScore)"?
			openList.sort(compareVertexByFScore);

			//Let currentNode = first item in openList || currentNode = openList.first();
			m_currentNode = openList.front();

			// Process the node, do what you want with it. EG:
			//if currentNode is endNode
			if (m_currentNode == endNode)
				//break out of loop
				break;

			else {
				//remove currentNode from openList
				openList.pop_front();
				//Add currentNode to closedList
				closedList.push_back(m_currentNode);

				//for all connections c in currentNode
				for (int i = 0; i < m_currentNode->m_edges.size(); i++) {

					Vertex* target = m_currentNode->m_edges[i]->m_target;

					float cost = m_currentNode->m_edges[i]->m_cost;

					//Add c.target to openList if not in closedList
					auto it = std::find(closedList.begin(), closedList.end(), target);

					if (it == closedList.end()) // Not in the closed list
					{
						//c.target.gScore = currentNode.gScore + c.cost
						target->m_gScore = m_currentNode->m_gScore + cost;

						target->m_hScore = target->m_position.distance(endNode->m_position);

						target->m_fScore = target->m_gScore + target->m_hScore;

						//c.target.parent = currentNode
						target->m_parent = m_currentNode;

						// Add it to the open list
						openList.push_back(target);
					}
				}
			}
		}

		// Calculate Path, in this example as positions
		//Let path be a Stack of Vector2
		// Clear any old path data...
		path.clear();

		//Let currentNode = endNode;
		m_currentNode = endNode;

		//While currentNode is not null
		while (m_currentNode != nullptr)
		{
			//Add currentNode.position to path
			path.push_front(m_currentNode);
			//currentNode = currentNode.parent
			m_currentNode = m_currentNode->m_parent;
		}
		return true;
	}
}