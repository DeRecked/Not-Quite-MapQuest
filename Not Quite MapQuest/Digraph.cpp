// Digraph.cpp -- directed graph class
// c. 2017 T. O'Neil

#include <climits>
#include "Digraph.hpp"

unsigned int Digraph::noVertices() {
	return numberOfVertices;
}

unsigned int Digraph::noEdges() {
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

}