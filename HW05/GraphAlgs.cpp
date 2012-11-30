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

std::pair<std::vector<NodeID>, EdgeWeight> TSP(Graph* G){


}
//Pseudo-code foundation from lecture 11/20
void tour(int* arr, int size, int startingPoint){
	if(size - startingPoint == 1){
		//check if arr is better than bestTour
	} else {
		for(int i = startingPoint; i < size; i ++){
			//swap(arr(startingPoint), arr(i));
			tour(arr, size, startingPoint++);
			//swap(arr(startingPoint), arr(i));
		}
	}
}