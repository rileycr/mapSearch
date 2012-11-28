/**
* @file MatrixGraph.cpp
* CSE 274 - Fall 2012
*
* @author Cooper Riley
*
* @note This is the implimentation of the MatrixGraph.h provided for 
* this assignment.
*/

#include "MatrixGraph.h"


MatrixGraph::MatrixGraph(unsigned num_nodes){
	num_edges = 0;
	M.resize(num_nodes);
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
	int degree = 0;
	if(0 <= u && u < M.size()){
		for(int i = 0; i < M.at(u).size() ; i++){
			if(M.at(u).at(i) != 0)
				degree++;
		}
	} else {
		return;
	}
	return degree;
}

unsigned MatrixGraph::size() const{
	return M.size();
}

unsigned MatrixGraph::numEdges() const{
	return num_edges;
}