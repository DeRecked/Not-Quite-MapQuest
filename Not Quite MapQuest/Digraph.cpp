// Digraph.cpp -- directed graph class
// c. 2017 T. O'Neil

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
	// Fill each vector element with a zero or INF (i.e. no edges)
	for (int i = 0; i < numberOfVertices; i++)
		for (int j = 0; j < numberOfVertices; j++)
			if (i == j) distMatrix[i][j] = 0;
			else distMatrix[i][j] = INF;
}

void Digraph::addEdge(int source, int dest, int wt) {
	// Add edge to adjacency matrix; increment number of edges 
	if (source == dest) distMatrix[source][dest] = 0;
	else distMatrix[source][dest] = wt;
	numberOfEdges++;
}

void Digraph::delEdge(int source, int dest) {
	// Remove edge from adjadency matrix; decrement number of edges
	if (source == dest) distMatrix[source][dest] = 0;
	else distMatrix[source][dest] = INF;
	numberOfEdges--;
}

int Digraph::isEdge(int source, int dest) {
	// Find and return edge between two verticies
	return distMatrix[source][dest];
}

int Digraph::dijkstra(int source, int dest) {
	// Vector to hold shortest path from source to dest, initialized to INF
	std::vector<int> shortestPath(numberOfVertices, INF);

	// Source has distance of zero
	shortestPath[source] = 0;

	// Find shortest path for all verticies
	for (int i = 0; i < numberOfVertices - 1; i++) {
		int min = INF, v;

		// Find the next vertex with the shortest distance
		for (int j = 0; j < numberOfVertices; j++) {
			if (vertex[j]->getStatus() == NOT_VISITED && shortestPath[j] <= min) {
				min = shortestPath[j];
				// v <- index to shortest path
				v = j;
			}
		}
		// Vertex marked as VISITED
		vertex[v]->setStatus(VISITED);

		// Update distance values at new vertex
		for (int w = 0; w < numberOfVertices; w++) {
			// If i has not been visited, is connected to the vertex, and is less than shortestPath so far...
			if (vertex[w]->getStatus() == NOT_VISITED && isEdge(w, v) && shortestPath[v] != INF
				&& shortestPath[v] + isEdge(v, w) < shortestPath[w])
				// Update shortestPath with new distance
				shortestPath[w] = shortestPath[v] + isEdge(v, w);
		}
	}
	// Reset all verticies back to NOT_VISITED
	for (int i = 0; i < vertex.size(); i++)
		vertex[i]->setStatus(NOT_VISITED);

	// Return shortest path from source to dest
	return shortestPath[dest];
}