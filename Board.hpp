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
	
	//if you have a road you need to be able to find the roads that are connected to it and vice versa. maps used here to find the vector of connections;
	//nodes also need to connect to Tiles
	//TODO: find out why compiler error when I make the vectors of references to an instance instead of just to an instance
	std::map<Road, std::vector<Node > > road2node;

	std::map<Node, std::vector<Road > > node2road;

	std::map<Node, std::vector<Tile > > node2tile;



};

#endif