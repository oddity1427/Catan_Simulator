#ifndef _SETTLEMENT_HPP
#define _SETTLEMENT_HPP

#include "Player.hpp"

//there are only 2 levels that a settlement can have, it will be useful to be able to reference them directly
//added null option
int const NO_BUILDING 	= 0;
int const SETTLEMENT 	= 1;
int const CITY 			= 2;

//Not sure how I am going to implement player actions yet, Settlement really might only end up keeping track of this information
struct Settlement{

	int level;
	Player owner;

};

#endif