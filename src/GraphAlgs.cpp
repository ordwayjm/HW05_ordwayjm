#include "GraphAlgs.h"

EdgeWeight bestTourLength;
Graph* graph;
int* bestTour;

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
	bestTourLength = 0.0;
	graph = G;
	
	// int* to hold indices of G
	bestTour = new int[numNodes];
	int* arr = new int[numNodes];

	// initialize best tour/node arrays with indices
	for(int i = 0; i < numNodes; i++)
	{
		arr[i] = i;
		bestTour[i] = i;
	}
	// initialize base tour case
	bestTourLength = getTourLength(bestTour, numNodes);
	
	tour(arr, numNodes, 1);
	
	// switch over to vector to match output
	std::vector<NodeID> bestTourVector;
	for(int i = 0; i < numNodes; i++)	
	{
		bestTourVector.push_back(bestTour[i]);
	}

	return std::pair<std::vector<NodeID>,EdgeWeight>(bestTourVector, bestTourLength);
}

/*
 * Brute Force, check every possible node combination.
 * Based on tour code shown in class.
 */
void tour(int* arr, int n, int startingPlace)
{
	EdgeWeight currTourLength;
	if(n - startingPlace == 1) 
	{
		currTourLength = getTourLength(arr, n);
		if(currTourLength < bestTourLength) 
		{
			bestTourLength = currTourLength;
			for(int i = 0; i < n; i++)
			{
				bestTour[i] = arr[i];
			}
		}
	}
	else 
	{
		for(int i = startingPlace; i < n; i++) 
		{
			swap(arr, arr[startingPlace], arr[i]);
			tour(arr, n, startingPlace + 1);
			swap(arr, arr[startingPlace], arr[i]);
		}
	}
}

/*
 * Adds up the length of the tour in array arr, terminates early if calculated length is larger than best so far
 */
EdgeWeight getTourLength(int* arr, int n)
{
	EdgeWeight length = 0;
	for(int i = 0; i < n - 1; i++)
	{
		length += graph->weight(arr[i], arr[i+1]);
	}
	// get last node weight
	length += graph->weight(arr[n - 1], arr[0]);
	return length;
}

/*
 * Swaps arr[a] with arr[b]
 */
void swap(int* arr, int a, int b)
{
	int temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
}