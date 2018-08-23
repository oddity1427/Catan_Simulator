#ifndef BOARD_HPP_FLAG
#define BOARD_HPP_FLAG

#include <vector>
#include <map>
#include "Node.hpp"
#include "Road.hpp"
#include "Tile.hpp"


int const STANDARD   = 0;
int const SIX_PLAYER = 1;
int const REGULAR    = 1; 


class Board{
private:
	void printVect(std::vector<int>);

	std::map<std::vector<int>,Tile *> 	masterTiles;
	std::map<std::vector<int>,Road *> 	masterRoads;
	std::map<std::vector<int>,Node *> 	masterNodes;

	std::vector<int> addVect(std::vector<int>*, std::vector<int>*);
	std::vector<int> addVect(std::vector<int>, std::vector<int>);
	std::vector<int> tileTileClockDir(std::vector<int>);

	void createTileLine(std::vector<int>, std::vector<int>, int);
	void fillNodes();
	void fillRoads();
	void fillTiles(std::vector<int>);
	void completeFromTiles();

public:

	std::vector<std::vector<int>> 		tile2roadVectors;
	std::vector<std::vector<int>> 		tile2nodeVectors;
	std::vector<std::vector<int>> 		tile2tileVectors;
	std::vector<std::vector<int>> 		node2roadVectorsPossible;


	Board();
	void buildBoard();
	void buildBoard(int, int);
	void buildBoard(std::vector<int>, std::vector<int>, std::vector<int>);
	void checkBoard();

};


#endif