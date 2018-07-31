#ifndef TILE_HPP_FLAG
#define TILE_HPP_FLAG

#include "Resource.hpp"

//each tile just has this information that other classes will access
class Tile {
public:
	int id;
	int resourceType;
	int dieNumber;

	Tile(int);
};

#endif