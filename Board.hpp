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
	std::vector<Node> masterNodes;
	std::vector<Road> masterRoads;

	std::vector<std::vector<int>> tile2roadVectors;
	std::vector<std::vector<int>> tile2nodeVectors;
	std::vector<std::vector<int>> tile2tileVectors;

	std::vector<int> addVect(std::vector<int>*, std::vector<int>*);
	std::vector<int> addVect(std::vector<int>, std::vector<int>);
	std::vector<int> tileTileClockDir(std::vector<int>);

public:
	Board();
	void buildBoard();
	void buildBoard(int, int);
	void buildBoard(std::vector<int>, std::vector<int>, std::vector<int>);
	void checkBoard();

};


#endif