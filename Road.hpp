#ifndef ROAD_HPP_FLAG
#define ROAD_HPP_FLAG

//#include "Player.hpp"
#include <vector>

class Node;
class Player; 

class Road{
private:
	std::vector<int> id;
	bool taken;
	Player* owner;
	std::vector<Node *> conNodes;

public:
	Road(std::vector<int>);

	void setOwner(Player *);
	void addNode(Node *);

	Node * getOtherNode(Node *);
	Player * getOwner();
	bool isTaken();

	const std::vector<int> getID();



};

#endif