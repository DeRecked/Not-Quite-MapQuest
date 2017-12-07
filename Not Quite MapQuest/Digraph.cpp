// Digraph.cpp -- directed graph class
// c. 2017 T. O'Neil

#include <climits>
#include <map>
#include "Digraph.hpp"

#define V 8

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

int minDistance(std::vector<int> dist, std::vector<bool> sptSet, int size) {
	// Initialize min value
	int min = 9999, min_index;

	for (int v = 0; v < size; v++)
		if (sptSet[v] == false && dist[v] <= min)
			min = dist[v], min_index = v;

	return min_index;
}

int Digraph::dijkstra(int source, int dest) {
	std::vector<int> dist(numberOfVertices);     // The output array.  dist[i] will hold the shortest
					 // distance from src to i

	std::vector<bool> sptSet(numberOfVertices); // sptSet[i] will true if vertex i is included in shortest
					// path tree or shortest distance from src to i is finalized

					// Initialize all distances as INFINITE and stpSet[] as false
	for (int i = 0; i < numberOfVertices; i++)
		dist[i] = 9999, sptSet[i] = false;

	// Distance of source vertex from itself is always 0
	dist[source] = 0;

	// Find shortest path for all vertices
	for (int count = 0; count < numberOfVertices - 1; count++)
	{
		// Pick the minimum distance vertex from the set of vertices not
		// yet processed. u is always equal to src in first iteration.
		int u = minDistance(dist, sptSet, numberOfVertices);

		// Mark the picked vertex as processed
		sptSet[u] = true;

		// Update dist value of the adjacent vertices of the picked vertex.
		for (int v = 0; v < numberOfVertices; v++)

			// Update dist[v] only if is not in sptSet, there is an edge from 
			// u to v, and total weight of path from src to  v through u is 
			// smaller than current value of dist[v]
			if (!sptSet[v] && distMatrix[u][v] && dist[u] != 9999
				&& dist[u] + distMatrix[u][v] < dist[v])
				dist[v] = dist[u] + distMatrix[u][v];
	}
	return dist[dest];
}