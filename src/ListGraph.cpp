#include "ListGraph.h"

ListGraph::ListGraph(int numNodes) 
{
	num_edges = 0;
	edgeList.resize(numNodes);
}

ListGraph::~ListGraph() {}

// Modifiers
void ListGraph::addEdge(NodeID u, NodeID v, EdgeWeight weight)
{
	// TODO
}
  
// Inspectors
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

std::list<NWPair> ListGraph::getAdj(NodeID u) const 
{ 
	return edgeList[u];
}

unsigned ListGraph::degree(NodeID u) const
{
	return edgeList[u].size();
}

unsigned ListGraph::size() const
{
	return edgeList.size();
}

unsigned ListGraph::numEdges() const
{
	return num_edges;
}



