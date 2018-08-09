#ifndef 	NODE_CPP_FLAG
#define		NODE_CPP_FLAG

#include 	"Node.hpp"

Node::Node(std::vector<int> ID){
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

void Node::setPortType(Resource r){
	portHere = true;
	portType = r;
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

bool Node::hasPort(){
	return portHere;
}

Resource Node::getPortType(){
	return portType;
}

const std::vector<int> Node::getID(){
	return id;
}

#endif