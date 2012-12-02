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
#include "StarbucksMap.h"

int* bestTour_;
float bestTourLength_;
Graph* current_graph_;
void tour(int* arr, int size, int startingPoint);
EdgeWeight tourDistance(int* arr, int num_nodes);
void swap(int* arr, int first, int second);

std::pair<std::vector<NodeID>, EdgeWeight> TSP(Graph* G){
	current_graph_ = G;

	int num_nodes = G -> size();
	std::vector<NodeID> bestTourNodes (num_nodes);
	bestTour_ = new int[num_nodes];

	for(int i = 0; i < num_nodes; i++){
		bestTour_[i] = i;  //Initalize as a starting point to find best tour
	}
	bestTourLength_ = tourDistance(bestTour_, num_nodes);   //Initalizes the distance for the first tour

	tour(bestTour_, num_nodes, 0);
	for(int i = 0; i < num_nodes; i++){
		bestTourNodes[i] = bestTour_[i];
	}
	
	std::pair<std::vector<NodeID>, EdgeWeight> finalTour(bestTourNodes, bestTourLength_);
	
	return finalTour;
}

//Pseudo-code foundation from lecture 11/20
void tour(int* arr, int size, int startingPoint){
	if(size - startingPoint == 1){
		EdgeWeight currDist = tourDistance(arr, size);
		if(currDist < bestTourLength_){
			for(int i = 0; i < size; i++){
				bestTour_[i] = arr[i];  //Makes 'bestTour_' the new tour which is shorter than it was
			}
			bestTourLength_ = currDist;
		}
	} else {
		for(int i = startingPoint; i < size; i++){
			swap(arr, startingPoint, i);
			//TODO: Check to see if we can cut off recursion here if this tour is already too long
			tour(arr, size, startingPoint + 1);
			swap(arr, startingPoint, i);
		}
	}
}

EdgeWeight tourDistance(int* arr, int num_nodes){
	EdgeWeight tourDist = 0;
	for(int i = 0; i < num_nodes - 1; i++){                     //num_nodes - 1 accounts for counting the distance between
		tourDist += current_graph_ -> weight(arr[i], arr[i+1]); //between the last two nodes before adding distance back to start
	}
	tourDist += current_graph_ -> weight(arr[num_nodes-1], arr[0]); //Distance from end back to start
	return tourDist;
}

void swap(int* arr, int first, int second){
	int temp = arr[first];
	arr[first] = arr[second];
	arr[second] = temp; arr;
}