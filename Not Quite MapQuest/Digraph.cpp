// Digraph.cpp -- directed graph class
// c. 2017 T. O'Neil

#include <climits>
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
			distMatrix[i][j] = INT_MAX;
}

void Digraph::addEdge(int source, int dest, int wt) {
	// Add distance to distance matrix; increment number of edges 
	distMatrix[source][dest] = wt;
	numberOfEdges++;
}

void Digraph::delEdge(int source, int dest) {
	// Remove distance from distance matrix; decrement number of edges
	distMatrix[source][dest] = INT_MAX;
	numberOfEdges--;
}

int Digraph::isEdge(int source, int dest) {
	// Find and return distance from distance matrix
	return distMatrix[source][dest];
}

int Digraph::dijkstra(int source, int dest) {

	std::vector<bool> path(numberOfVertices);
	std::vector<int> distance(numberOfVertices);
	int min, min_index;
					
	for (int i = 0; i < numberOfVertices; i++)
		distance[i] = INT_MAX, path[i] = false;

	distance[source] = 0;

	for (int count = 0; count < numberOfVertices - 1; count++)	{
		for (int v = 0; v < numberOfVertices; v++)
			if (path[v] == false && distance[v] <= INT_MAX)
				min = distance[v], min_index = v;

		path[min_index] = true;

		for (int v = 0; v < numberOfVertices; v++)
			if (!path[v] && distMatrix[min_index][v] && distance[min_index] != INT_MAX
				&& distance[min_index] + distMatrix[min_index][v] < distance[v])
				distance[v] = distance[min_index] + distMatrix[min_index][v];
	}

	for (int i = 0; i < distance.size(); i++)
		cout << "distance[" << i << "] = " << distance[i] << endl;

	return distance[dest];
}

//int Digraph::dijkstra(int source, int dest) {
//
//	std::vector<int> distance(numberOfVertices);
//	std::vector<int> previous(numberOfVertices);
//	int minDistance = INT_MAX;
//	int closestVertex;
//	int count = 0;
//
//	vertex[source]->setStatus(VISITED);
//
//	for (int i = 0; i < numberOfVertices; i++)
//		distance[i] = INT_MAX;
//
//	while (count < numberOfVertices) {
//		for (int i = 0; i < numberOfVertices; i++) {
//			if ((vertex[i]->getStatus() == NOT_VISITED) && (minDistance >= distance[i])) {
//				minDistance = distance[i];
//				closestVertex = i;
//			}
//		}
//
//		vertex[closestVertex]->setStatus(VISITED);
//
//		for (int i = 0; i < numberOfVertices; i++) {
//			if (vertex[i]->getStatus() == NOT_VISITED) {
//				if (distance[i] > distance[closestVertex] + distMatrix[closestVertex][i]) {
//					distance[i] = distance[closestVertex] + distMatrix[closestVertex][i];
//					previous[i] = closestVertex;
//				}
//			}
//		}
//		count++;
//	}
//	return distance[dest];
//}