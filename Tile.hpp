#ifndef TILE_HPP_FLAG
#define TILE_HPP_FLAG

#include "Resource.hpp"

//each tile just has this information that other classes will access
struct Tile {
	int const id;
	int resourceType;
	int dieNumber;
};

#endif