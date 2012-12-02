#include "GraphAlgs.h"

/*
 * Solves the Traveling Salesperson Problem: finding the shortest cycle through a graph that 
 * vists every node exactly once (with exception of the first node, which is repeated as the 
 * last node in the cycle.)
 * 
 * Return value: Return a pair, with the first element being a vector of length n listing the 
 * order of the nodes in the cycle, and the second element being the length of that path.
 */
std::pair<std::vector<NodeID>, EdgeWeight> TSP(Graph* G)
{
	int numNodes = G->size();
	double tourLength = 0.0;
	std::vector<NodeID> bestTour = std::vector<NodeID>(numNodes);

	return std::pair<std::vector<NodeID>,EdgeWeight>(bestTour, tourLength);
}


