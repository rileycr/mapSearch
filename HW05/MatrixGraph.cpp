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

//This initializes each edgeWeight for each vector to -1 meaning
//there is no edge between the nodes.
MatrixGraph::MatrixGraph(unsigned num_nodes){
	num_edges = 0;
	M.resize(num_nodes);
	for(int i = 0; i < num_nodes; i++){
		M.at(i).resize(num_nodes);
		for(int j = 0; j < num_nodes; j++){
			M.at(i).at(j) = -1;
		}
	}
}

MatrixGraph::~MatrixGraph(){

}

void MatrixGraph::addEdge(NodeID u, NodeID v, EdgeWeight weight){
	if(0 <= u && u < M.size() && 0 <= v && v < M.size() && u != v && weight > 0){
		if(M.at(u).at(v) == -1){
			M.at(u).at(v) = weight;
			M.at(v).at(u) = weight;
			num_edges++;
		}
	}
}

EdgeWeight MatrixGraph::weight(NodeID u, NodeID v) const{
	EdgeWeight weight = 0;
	if(0 <= u && u < M.size() && 0 <= v && v < M.size()){
		weight =  M.at(u).at(v);
	}
	if(weight = -1)
		weight = 0;
	return weight;
}

std::list<NWPair> MatrixGraph::getAdj(NodeID u) const{
	std::list<NWPair>* adjNodes = new std::list<NWPair>;
	for(int i = 0; i < M.at(u).size(); i++){
		NWPair cur(i, M.at(u).at(i));
		if(cur.second != 0)
			adjNodes -> push_back(cur);
	}
	return *adjNodes;
}

unsigned MatrixGraph::degree(NodeID u) const{
	unsigned degree = 0;
	if(0 <= u && u < M.size()){
		for(unsigned i = 0; i < M.at(u).size() ; i++){
			if(M.at(u).at(i) != -1)
				degree++;
		}
	} 
	return degree;
}

unsigned MatrixGraph::size() const{
	return M.size();
}

unsigned MatrixGraph::numEdges() const{
	return num_edges;
}