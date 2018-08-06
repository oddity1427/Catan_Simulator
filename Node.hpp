#ifndef _NODE_HPP
#define _NODE_HPP

#include "Player.hpp"
#include "Tile.hpp"
#include "Road.hpp"
#include <vector>

//there are only 2 levels that a settlement can have, it will be useful to be able to reference them directly
//added null option
const int NO_BUILDING 	= 0;
const int SETTLEMENT 	= 1;
const int CITY 			= 2;


class Node{
private:

	int id;
	int building;
	bool claimed; 
	Player * owner;
	std::vector<Tile *> tiles; 
	std::vector<Road *> roads;

public:

	Node(int);

	void setPlayer(Player *);
	void addTile(Tile *);
	void addRoad(Road *);

	std::vector<Tile *>* getTiles();
	std::vector<Road *>* getRoads();
	Player * getOwner(); 
	bool isClaimed();
	int getBuilding(); 

};

#endif