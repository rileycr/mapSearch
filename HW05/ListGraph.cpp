/**
* @file ListGraph.cpp
* CSE 274 - Fall 2012
*
* @author Cooper Riley
*
* @note This is the implimentation of the ListGraph.h provided for 
* this assignment.
*/

#include "ListGraph.h"

ListGraph::ListGraph(int numNodes){
	num_edges = 0;
	edgeList.resize(numNodes);
}

ListGraph::~ListGraph(){

}

void ListGraph::addEdge(NodeID u, NodeID v, EdgeWeight weight){


}

EdgeWeight ListGraph::weight(NodeID u, NodeID v) const {


	return 0.0;
}

std::list<NWPair> ListGraph::getAdj(NodeID u) const {

	return edgeList[u];
}

unsigned ListGraph::degree(NodeID u) const {
	int degree = 0;
	if(0 <= u && u < edgeList.size()){
		degree = edgeList[u].size();
	} 
	return degree;
}

unsigned ListGraph::size() const {


	return 0;
}

unsigned ListGraph::numEdges() const {

	return num_edges;
}