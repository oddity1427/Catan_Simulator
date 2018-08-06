#ifndef 	NODE_CPP_FLAG
#define		NODE_CPP_FLAG

#include 	"Node.hpp"

Node::Node(int ID){
	id = ID;

}

void Node::setPlayer(Player * p){
	claimed = true;
	owner = p;
}

void Node::addTile(Tile * t){
	conTiles.push_back(t);
}

void Node::addRoad(Road * r){
	conRoads.push_back(r);
}

std::vector<Tile *> *  Node::getTiles(){
	return &conTiles;
}

std::vector<Road* > * Node::getRoads(){
	return &conRoads;
}

Player * Node::getOwner(){
	return owner;
} 

bool Node::isClaimed(){
	return claimed;
}

int Node::getBuilding(){
	return building;
}

#endif