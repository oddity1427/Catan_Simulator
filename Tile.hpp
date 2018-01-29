#ifndef _TILE_HPP
#define _TILE_HPP

//define names for all of the tile types in the game
int const DESERT_TILE 	= 0;
int const SHEEP_TILE 	= 1;
int const BRICK_TILE 	= 2;
int const WOOD_TILE 	= 3;
int const WHEAT_TILE 	= 4;
int const STONE_TILE 	= 5;

//each tile just has this information that other classes will access
struct Tile {
	int resourceType;
	int dieNumber;
};

#endif