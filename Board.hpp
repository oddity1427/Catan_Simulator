#ifndef _BOARD_HPP
#define _BOARD_HPP

//board is going to be used to avoid circular inclusions between roads and nodes, and allow for random access by players instead of searching through as a linked list
#include "Road.hpp"
#include "Node.hpp"
#include <map>

struct Board
{
	
	//if you have a road you need to be able to find the roads that are connected to it and vice versa. maps used here to find the vector of connections;
	std::map<Road&, std::vector<Node&>> road_Connect;

	std::map<Node&, std::vector<Road&>> node_Connect;

};

#endif