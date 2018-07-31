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
public:

	int id;
	int settlement;
	Player* owner;
	std::vector<Tile> tiles; 
	std::vector<Road> roads;

	Node(int, Player);

};

#endif