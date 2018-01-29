#ifndef _ROAD_HPP
#define _ROAD_HPP

int const NO_ROAD 	= 0;
int const ROAD 		= 1;

//This seems a little bit rediculous but having a type will make this more obvious and readable in other classes;	
struct Road
{
	int state;
};

#endif