#ifndef _BOARD_HPP
#define _BOARD_HPP

//board is going to be used to avoid circular inclusions between roads and nodes, and allow for random access by players instead of searching through as a linked list
#include "Road.hpp"
#include "Node.hpp"
#include "Tile.hpp"
#include <map>
#include <vector>

struct Board
{
	
	//structures that capture the connections between pieces of the board.
	//the key of the maps is an int const id in road, node, and tile.
	//this will be inserted at creation and allow for the concrete location to be found for bugfixing
	std::map<int, std::vector<Node& > > road2node;
	std::map<int, std::vector<Road& > > node2road;
	std::map<int, std::vector<Tile& > > node2tile;

	// vectors to hold all of the salient board pieces;
	std::vector<Node> allNodes;
	std::vector<Tile> allTiles;
	std::vector<Road> allRoads;

};

#endif