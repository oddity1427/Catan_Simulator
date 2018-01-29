#ifndef _NODE_HPP
#define _NODE_HPP

//the node itself doesn't need to have any particular idea where it is on the board
//that will be handled in the board creation, nodes just need to tie together other data and classes

struct Node{

	//TODO: decide how nodes and roads are going to reference each other without including each other: current ideas include making a larger board class that includes most of the current classes as subclasses, or making some sort of map class that holds all of the pieces of the board and their relationships so that the classes like node don't need to be linked to their neighbors; solution may be some combination of those things
	

};

#endif