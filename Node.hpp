#ifndef _NODE_HPP
#define _NODE_HPP

//commented out to make room for the forward declaration testing below
//#include "Player.hpp"
//#include "Tile.hpp"
//#include "Road.hpp"
//have to actually include resource because we store it and not just a pointer to it
#include "Resource.hpp"
#include <vector>

const int NO_BUILDING 	= 0;
const int SETTLEMENT 	= 1;
const int CITY 			= 2;

//testing out forward inclusions to remove circular dependencies; seeAlso Tile.hpp
class Tile;
class Player;
class Road;


class Node{
private:

	int id;
	int building;
	bool claimed;
	bool portHere;
	Resource portType; 
	Player * owner;
	std::vector<Tile *> conTiles; 
	std::vector<Road *> conRoads;

public:

	Node(int);

	void setPlayer(Player *);
	void addTile(Tile *);
	void addRoad(Road *);

	void setPortType(Resource);


	std::vector<Tile *>* getTiles();
	std::vector<Road *>* getRoads();
	Player * getOwner(); 
	bool isClaimed();
	int getBuilding(); 

	bool hasPort();
	Resource getPortType();

};

#endif