#ifndef TILE_HPP_FLAG
#define TILE_HPP_FLAG

//commented out for the forward declaration testing below
//#include "Resource.hpp"
//#include "Node.hpp"
#include <vector>

//testing forward declarations to remove circular dependencies: seeAlso: Node.hpp
class Resource;
class Node;


class Tile {
private:
	int id;
	int resourceType;
	int dieNumber;

	std::vector<Node *> conNodes;

public:
	Tile(int);

	void setResourceType(int);
	void setDieNumber(int);
	void addNode(Node *);

	int getResourceType();
	int getDieNumber();
	std::vector<Node * > * getConNodes();

};

#endif