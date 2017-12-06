// Digraph.cpp -- directed graph class
// c. 2017 T. O'Neil

#include <climits>
#include <map>
#include "Digraph.hpp"

unsigned int Digraph::noVertices() {
	// Return total number of verticies
	return numberOfVertices;
}

unsigned int Digraph::noEdges() {
	// Return total number of edges
	return numberOfEdges;
}

void Digraph::resetEdges() {
	// Fill each vector element with max int value to represent infinity
	for (int i = 0; i < numberOfVertices; i++)
		for (int j = 0; j < numberOfVertices; j++)
			if (i == j) distMatrix[i][j] = 0;
			else distMatrix[i][j] = INT_MAX;
}

void Digraph::addEdge(int source, int dest, int wt) {
	// Add distance to distance matrix; increment number of edges 
	if (source == dest) distMatrix[source][dest] = 0;
	else distMatrix[source][dest] = wt;
	numberOfEdges++;
}

void Digraph::delEdge(int source, int dest) {
	// Remove distance from distance matrix; decrement number of edges
	if (source == dest) distMatrix[source][dest] = 0;
	else distMatrix[source][dest] = INT_MAX;
	numberOfEdges--;
}

int Digraph::isEdge(int source, int dest) {
	// Find and return distance from distance matrix
	return distMatrix[source][dest];
}

int Digraph::dijkstra(int source, int dest) {

	// Store path from source to dest
	std::vector<int> path;
	// Record the previous vertex
	std::vector<int> prev;

	// Mark source as VISITED

	// WHILE verticies in vector::vertex have not been visited:
		// Find vertex u with smallest weight
		// Mark as VISITED
		// FOR EACH neighbor v of u:
			// wtSum = dist(u) + isEdge(u,v)
			// IF wtSum < dist(u):
				// dist[v] = wtSum;
				// prev[v] = u;
			//
		//
	//
}

//int Digraph::dijkstra(int source, int dest) {
//
//	std::map<int, int> history;	
//	int location = source, nextVertex = 0, shortestDistance = INT_MAX, wtSum = 0;
//
//	// Add source to history map
//	history[source] = 0;
//
//	// Mark source as VISITED
//	vertex[source]->setStatus(VISITED);
//	
//	// While dest is not yet reached
//	while (location != dest) {
//		for (int i = 0; i < numberOfVertices; i++) {
//			if (distMatrix[source][i] < shortestDistance && distMatrix[source][i] != 0)
//				shortestDistance = distMatrix[source][i];
//			nextVertex = i;
//		}
//
//		// Add next vertex to history map
//		history[nextVertex] = distMatrix[source][nextVertex];
//		
//		// Mark next vertex as VISITED
//		vertex[nextVertex]->setStatus(VISITED);
//		
//		// Sum weight from source to current location
//		for (auto iter = history.begin(); iter != history.end(); ++iter)
//			wtSum += iter->second;
//
//		// If sum < previous known weight, go back
//		if (wtSum < shortestDistance)
//			shortestDistance = wtSum;
//	}
//
//	// Return new distance from source to dest
//	return shortestDistance;
//}