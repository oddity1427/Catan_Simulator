#ifndef RESOURCE_HPP_FLAG
#define RESOURCE_HPP_FLAG

//define names for all of the tile types in the game
int const NO_RESOURCE 	= 0;
int const SHEEP 	 	= 1;
int const BRICK 		= 2;
int const WOOD 			= 3;
int const WHEAT 		= 4;
int const STONE 		= 5;

//this seems a little rediculous now but it will let me access the resource definitions in a logical way instead of defining it a bunch of times
//depending on how the program is looking when I implement players buying recipes, this may get rolled into another class
struct Resource
{
	
	int type;		

};

#endif