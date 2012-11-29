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
	if(0 <= u && u < edgeList.size() && 0 <= v && v < edgeList.size() && u != v && weight > 0){
		EList::iterator it;
		it = edgeList[u].begin();
		for(it = edgeList[u].begin(); it != edgeList[u].end(); it++){
			if(it -> first == v){
				return;
			} 
			it++;
		}
		edgeList[u].push_back(NWPair(v, weight));
		edgeList[v].push_back(NWPair(u, weight));
		num_edges++;
	}
}

EdgeWeight ListGraph::weight(NodeID u, NodeID v) const {


	return 0.0;
}

std::list<NWPair> ListGraph::getAdj(NodeID u) const {
	if(0 <= u && u < edgeList.size()){
		return edgeList[u];
	}
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