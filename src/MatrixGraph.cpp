#include "MatrixGraph.h"

MatrixGraph::MatrixGraph(unsigned num_nodes)
{
	M.resize(num_nodes);
}

MatrixGraph::~MatrixGraph() {}

// Modifiers
void MatrixGraph::addEdge(NodeID u, NodeID v, EdgeWeight weight) 
{

}
  
// Inspectors
EdgeWeight MatrixGraph::weight(NodeID u, NodeID v) const
{

}
std::list<NWPair> MatrixGraph::getAdj(NodeID u) const 
{

}

unsigned MatrixGraph::degree(NodeID u) const
{

}

unsigned MatrixGraph::size() const 
{

}

unsigned MatrixGraph::numEdges() const 
{

}