// Digraph.cpp -- directed graph class
// c. 2017 T. O'Neil

#include <climits>
#include "Digraph.hpp"

#define INF 2000000000

unsigned int Digraph::noVertices() {
	// Return total number of verticies
	return numberOfVertices;
}

unsigned int Digraph::noEdges() {
	// Return total number of edges
	return numberOfEdges;
}

void Digraph::resetEdges() {
	// Fill each vector element with max int value to represent INF9inity
	for (int i = 0; i < numberOfVertices; i++)
		for (int j = 0; j < numberOfVertices; j++)
			if (i == j) distMatrix[i][j] = 0;
			else distMatrix[i][j] = INF;
}

void Digraph::addEdge(int source, int dest, int wt) {
	// Add shortestPathance to shortestPathance matrix; increment number of edges 
	if (source == dest) distMatrix[source][dest] = 0;
	else distMatrix[source][dest] = wt;
	numberOfEdges++;
}

void Digraph::delEdge(int source, int dest) {
	// Remove shortestPathance from shortestPathance matrix; decrement number of edges
	if (source == dest) distMatrix[source][dest] = 0;
	else distMatrix[source][dest] = INF;
	numberOfEdges--;
}

int Digraph::isEdge(int source, int dest) {
	// Find and return shortestPathance from shortestPathance matrix
	return distMatrix[source][dest];
}

int Digraph::dijkstra(int source, int dest) {
	// Vector to hold shortest path from source to dest 
	std::vector<int> shortestPath(numberOfVertices, INF);

	// Source has distance of zero
	shortestPath[source] = 0;

	// Find shortest path for all verticies
	for (int count = 0; count < numberOfVertices - 1; count++) {

		int min = INF, minIndex;

		// Find the vertex with the shortest distance
		for (int v = 0; v < numberOfVertices; v++)
			if (vertex[v]->getStatus() == NOT_VISITED && shortestPath[v] <= min) {
				min = shortestPath[v];
				minIndex = v;
			}
		int u = minIndex;
		vertex[u]->setStatus(VISITED);

		for (int v = 0; v < numberOfVertices; v++)
			if (vertex[v]->getStatus() == NOT_VISITED && distMatrix[u][v] && shortestPath[u] != INF
				&& shortestPath[u] + distMatrix[u][v] < shortestPath[v])
				shortestPath[v] = shortestPath[u] + distMatrix[u][v];
	}

	// Reset all verticies back to NOT_VISITED
	for (int i = 0; i < vertex.size(); i++)
		vertex[i]->setStatus(NOT_VISITED);

	return shortestPath[dest];
}