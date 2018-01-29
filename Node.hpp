#ifndef _NODE_HPP
#define _NODE_HPP

//With the addition of the map class, Node effectively became a wrapper for the Settlement class
//therefore, settlement has been deleted and its information adopted here

#include "Player.hpp"

//there are only 2 levels that a settlement can have, it will be useful to be able to reference them directly
//added null option
int const NO_BUILDING 	= 0;
int const SETTLEMENT 	= 1;
int const CITY 			= 2;


struct Node{

	int const id;
	int settlement;
	Player owner;

};

#endif