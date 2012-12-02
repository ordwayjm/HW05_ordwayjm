#include "ListGraph.h"

ListGraph::ListGraph(int numNodes) 
{
	num_edges = 0;
	edgeList.resize(numNodes);
}

ListGraph::~ListGraph() {}

// Modifiers

/*
 * Add a weighted, undirected edge between nodes u and v.
 */
void ListGraph::addEdge(NodeID u, NodeID v, EdgeWeight weight)
{
	// add edge for u, v
	NWPair edge1 = NWPair(v, weight);
	edgeList[u].push_front(edge1);
	// add edge for v, u
	NWPair edge2 = NWPair(u, weight);
	edgeList[v].push_front(edge2);
	
	num_edges++;
}
  
// Inspectors

/*
 * Get the weight between nodes u and v; return 0 if there is no edge.
 */
EdgeWeight ListGraph::weight(NodeID u, NodeID v) const 
{
	EList::const_iterator it;
	for(it = edgeList[u].begin(); it != edgeList[u].end(); it++) 
	{
		NWPair tPair = (*it);
		if(tPair.first == v) 
		{
			return tPair.second;
		}
	}
	return 0.0;
}

/*
 * Return a list of NodeID/EdgeWeight pairs describing the nodes adjacent to edge u.
 */
std::list<NWPair> ListGraph::getAdj(NodeID u) const 
{ 
	return edgeList[u];
}

/*
 * Return the degree (i.e. the number of neighorbs) of node u.
 */
unsigned ListGraph::degree(NodeID u) const
{
	return edgeList[u].size();
}

/*
 * Return the number of nodes in the graph.
 */
unsigned ListGraph::size() const
{
	return edgeList.size();
}

/* 
 * Return the number of edges in the graph.
 */
unsigned ListGraph::numEdges() const
{
	return num_edges;
}



