#ifndef BOARD_HPP_FLAG
#define BOARD_HPP_FLAG

#include <vector>
#include "Node.hpp"
#include "Road.hpp"
#include "Tile.hpp"


int const STANDARD   = 0;
int const SIX_PLAYER = 1;
int const REGULAR    = 1; 


class Board{
private:
	std::vector<Tile> masterTiles;
	std::vector<Node> masterNode;
	std::vector<Road> masterRoad;


public:
	Board();
	void buildBoard();
	void buildBoard(int, int);
	void buildBoard(std::vector<int>, std::vector<int>, std::vector<int>);
	void checkBoard();

};


#endif