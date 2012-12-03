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
	EdgeWeight bestTourLength = 0.0;
	std::vector<NodeID> bestTour = std::vector<NodeID>(numNodes);


	return std::pair<std::vector<NodeID>,EdgeWeight>(bestTour, bestTourLength);
}

/*
 * Brute Force, check every possible node combination.
 * Based on tour code shown in class.
 */
void tour(int* arr, int n, int startingPlace, EdgeWeight bestTourLength)
{
	EdgeWeight currTourLength;
	if(n - startingPlace == 1) 
	{
		currTourLength = getTourLength(arr, bestTourLength);
		if(currTourLength < bestTourLength) 
		{
			bestTourLength = currTourLength;
		}
	}
	else 
	{
		currTourLength = getTourLength(arr, bestTourLength);
		if(currTourLength < bestTourLength) 
		{
			bestTourLength = currTourLength;
		}
		for(int i = startingPlace; i < n; i++) 
		{
			swap(arr, arr[startingPlace], arr[i]);
			tour(arr, n, startingPlace + 1, bestTourLength);
			swap(arr, arr[startingPlace], arr[i]);
		}
	}
}

/*
 * Adds up the length of the tour in array arr, compares with best so far to terminate early.
 */
EdgeWeight getTourLength(int* arr, EdgeWeight bestTourLength)
{
	return 0.0;
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




