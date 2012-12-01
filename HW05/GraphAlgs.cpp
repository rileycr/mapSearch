/**
* @file GraphAlgs.cpp
* CSE 274 - Fall 2012
*
* @author Cooper Riley
*
* @note This is the implimentation of the GraphAlgs.h provided for 
* this assignment.
*/

#include "GraphAlgs.h"
int* bestTour_;
float bestTourLength_;
Graph* current_graph_;

std::pair<std::vector<NodeID>, EdgeWeight> TSP(Graph* G){
	current_graph_ = G;
	std::pair<std::vector<NodeID>, EdgeWeight> finalTour;

	int num_nodes = G -> size();
	int* arr = new int[num_nodes];
	std::vector<NodeID> bestTourNodes;

	for(int i = 0; i < num_nodes; i++){
		bestTour_[i] = i;  //Initalize as a starting point to find best tour
	}
	bestTourLength_ = tourDistance(bestTour_, num_nodes);

	tour(bestTour_, num_nodes, 0);

	
	return finalTour;
}

//Pseudo-code foundation from lecture 11/20
void tour(int* arr, int size, int startingPoint){
	if(size - startingPoint == 1){
		EdgeWeight currDist = tourDistance(arr, size);
		if(currDist < bestTourLength_){
			for(int i = 0; i < size; i++){
				bestTour_[i] = arr[i];  //Makes 'bestTour' the new tour which is shorter
			}
			bestTourLength_ = currDist;
		}
	} else {
		for(int i = startingPoint; i < size; i ++){
			swap(arr, startingPoint, i);
			tour(arr, size, startingPoint++);
			swap(arr, startingPoint, i);
		}
	}
}

EdgeWeight tourDistance(int* arr, int num_nodes){
	EdgeWeight tourDist = 0;
	for(int i = 0; i < num_nodes; i++){
		tourDist += current_graph_ -> weight(arr[i], arr[i+1]);
	}
	tourDist += current_graph_ -> weight(arr[num_nodes], arr[0]); //Distance from end back to start

}

void swap(int* arr, int first, int second){
	int temp = arr[first];
	arr[first] = arr[second];
	arr[second] = temp;
}