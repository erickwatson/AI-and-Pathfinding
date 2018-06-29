#include "Graph.h"

void dijkstrasSearch(startNode, endNode)
{

	//Let openList be a List of Nodes
		//Let closedList be a List of Nodes

		//Set startNode.parent to null
		//Add startNode to openList

		//While (openList != empty)

			//Sort openList by Node.gScore || openList.sort(Node.gScore)"?

			//Let currentNode = first item in openList || currentNode = openList.first();

			// Process the node, do what you want with it. EG:
			//if currentNode is endNode
				//break out of loop

			//remove currentNode from openList
			//Add currentNode to closedList

			//for all connections c in currentNode
					//Add c.target to openList if not in closedList
					//c.target.gScore = currentNode.gScore + c.cost
					//c.target.parent = currentNode


	// Calculate Path, in this example as positions
	//Let path be a Stack of Vector2
	//Let currentNode = endNode;
	//While currentNode is not null
		//Add currentNode.position to path
		//currentNode = currentNode.parent
	

	return path;




}