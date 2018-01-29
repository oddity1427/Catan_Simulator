#ifndef _TILE_HPP
#define _TILE_HPP

#include "Resource.hpp"

//each tile just has this information that other classes will access
struct Tile {
	int resourceType;
	int dieNumber;
};

#endif