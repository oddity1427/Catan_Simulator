#ifndef 	NODE_CPP_FLAG
#define		NODE_CPP_FLAG

#include 	"Node.hpp"

Node::Node(int ID, Player p){
	id = ID;
	owner = &p;
}

#endif