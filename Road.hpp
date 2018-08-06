#ifndef ROAD_HPP_FLAG
#define ROAD_HPP_FLAG

//#include "Player.hpp"
#include <vector>

class Node;
class Player; 

class Road{
private:
	int id;
	bool taken;
	Player* owner;
	std::vector<Node *> conNodes;

public:
	Road(int);

	void setOwner(Player *);
	void addNode(Node *);

	Node * getOtherNode(Node *);
	Player * getOwner();
	bool isTaken();



};

#endif