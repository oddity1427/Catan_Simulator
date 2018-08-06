#ifndef TILE_CPP_FLAG
#define TILE_CPP_FLAG

#include "Tile.hpp"

Tile::Tile(int ID){
	id = ID;
}

void Tile::setResourceType(int r){
	resourceType = r;
}

void Tile::setDieNumber(int num){
	dieNumber = num;
}

void Tile::addNode(Node * node_p){
	conNodes.push_back(node_p);
}


int Tile::getResourceType(){
	return resourceType;
}

int Tile::getDieNumber(){
	return dieNumber;
}

std::vector<Node *>* Tile::getConNodes(){
	return &conNodes;
}

#endif