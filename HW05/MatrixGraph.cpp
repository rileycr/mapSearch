#include "MatrixGraph.h"


MatrixGraph::MatrixGraph(unsigned num_nodes){
	num_edges = 0;
	EList mGraph(num_nodes);
}

void MatrixGraph::addEdge(NodeID u, NodeID v, EdgeWeight weight){
	M.at(u).at(v) = weight;

	num_edges++;
}

EdgeWeight MatrixGraph::weight(NodeID u, NodeID v) const{
	return M.at(u).at(v);
}

//TODO Not sure if this works but it compiles
std::list<NWPair> MatrixGraph::getAdj(NodeID u) const{
	return EList(u);
}

unsigned MatrixGraph::degree(NodeID u) const{

}

unsigned MatrixGraph::size() const{

}

unsigned MatrixGraph::numEdges() const{
	return num_edges;
}