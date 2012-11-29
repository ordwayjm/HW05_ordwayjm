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
 * 
 * Preconditions: 
 *     u and v are legal labels (i.e. 0 <= u < G.size(), 0 <= v < G.size())
 *     u != v
 *     There is no edge between u and v.
 *     weight > 0
 */
void MatrixGraph::addEdge(NodeID u, NodeID v, EdgeWeight weight) 
{
	// TODO: add preconditions
	M[u][v] = weight;
	M[v][u] = weight;
	num_edges++;
}
  
// Inspectors

/*
 * Get the weight between nodes u and v; return 0 if there is no edge.
 *
 * Preconditions: 
 *     u and v are legal labels (i.e. 0 <= u < G.size(), 0 <= v < G.size())
 */
EdgeWeight MatrixGraph::weight(NodeID u, NodeID v) const
{
	// TODO: add preconditions
	return M[u][v];
}

/*
 * Return a list of NodeID/EdgeWeight pairs describing the nodes adjacent to edge w.
 *
 * Preconditions: u is a legal label.
 */
std::list<NWPair> MatrixGraph::getAdj(NodeID u) const 
{
	// TODO: add preconditions
	EList* adj = new EList();
	NWPair vertex;
	for(int i = 0; i < M[u].size(); i++)
	{ 
		if(M[u][i] == 1)
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
 *
 * Preconditions: u is a legal label;
 */
unsigned MatrixGraph::degree(NodeID u) const
{
	// TODO: add preconditions
	int degree = 0;
	for(int i = 0; i < M[u].size(); i++)
	{
		degree += M[u][i];
	}
	return degree;
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