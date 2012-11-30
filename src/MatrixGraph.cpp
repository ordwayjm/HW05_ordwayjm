#include "MatrixGraph.h"

MatrixGraph::MatrixGraph(unsigned num_nodes)
{
	num_edges = 0;
	M.resize(num_nodes);
	for(int i = 0; i < num_nodes; i++)
	{
		M[i].resize(num_nodes);
	}
}

MatrixGraph::~MatrixGraph() {}

// Modifiers

/*
 * Add a weighted, undirected edge between nodes u and v.
 */
void MatrixGraph::addEdge(NodeID u, NodeID v, EdgeWeight weight) 
{
	M[u][v] = weight;
	M[v][u] = weight;
	num_edges++;
}
  
// Inspectors

/*
 * Get the weight between nodes u and v; return 0 if there is no edge.
 */
EdgeWeight MatrixGraph::weight(NodeID u, NodeID v) const
{
	return M[u][v];
}

/*
 * Return a list of NodeID/EdgeWeight pairs describing the nodes adjacent to edge w.
 */
std::list<NWPair> MatrixGraph::getAdj(NodeID u) const 
{

	EList* adj = new EList();
	NWPair vertex;
	for(int i = 0; i < M[u].size(); i++)
	{ 
		if(M[u][i] != 0)
		{
			vertex.first = i; // get NodeID
			vertex.second = M[u][i]; // get EdgeWeight
			(*adj).push_back(vertex);
		}
	}
	return *adj;
}

/*
 * Return the degree (i.e. the number of neighorbs) of node u.
 */
unsigned MatrixGraph::degree(NodeID u) const
{
	return getAdj(u).size();
}

/*
 * Return the number of nodes in the graph.
 */
unsigned MatrixGraph::size() const 
{
	return M.size();
}

/* 
 * Return the number of edges in the graph.
 */
unsigned MatrixGraph::numEdges() const 
{
	return num_edges;
}