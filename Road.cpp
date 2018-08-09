#ifndef ROAD_CPP_FLAG
#define ROAD_CPP_FLAG

#include "Road.hpp"
#include <iostream>

Road::Road(std::vector<int> ID){
	id = ID;
	taken = false;
}

//claiming does not check if the road is taken because the player interface will have to check anyway
void Road::setOwner(Player * p){
	owner = p; 
}

void Road::addNode(Node * nodeP){
	conNodes.push_back(nodeP);
}

bool Road::isTaken(){
	return taken;
}

Player * Road::getOwner(){
	return owner;
}

Node * Road::getOtherNode(Node * n_p){
	for(unsigned i = 1; i < 3; i++){
		if(conNodes[i] != n_p){
			return(conNodes[i]);
		}
	}
	//not really a great way to do errors, but simple, and works for something that I see in advance has the potential to crash
	//this comment will stand as a marker for placs that have priority when implementing error handling 
	std::cout << "Error, all Nodes * in conNodes are equal to input Node *  ; Road.cpp:35";
}

const std::vector<int> Road::getID(){
	return id;
}

#endif