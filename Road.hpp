#ifndef ROAD_HPP_FLAG
#define ROAD_HPP_FLAG

int const NO_ROAD 	= 0;
int const ROAD 		= 1;

//This seems a little bit rediculous but having a type will make this more obvious and readable in other classes;	
struct Road
{
	int const id;
	int state;
};

#endif