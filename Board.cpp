#include "Board.hpp"
#include <iterator> 
#include <algorithm>


Board::Board() {

	//The pool of 19 resources (including desert/noresource) that each tile is randomly assigned
	std::vector<int> tileTypePool = {NO_RESOURCE, STONE, STONE, STONE, BRICK, BRICK, BRICK, WHEAT, WHEAT, WHEAT, WHEAT, SHEEP, SHEEP, SHEEP, SHEEP, WOOD, WOOD, WOOD, WOOD};
	std::random_shuffle(tileTypePool.begin(), tileTypePool.end() );

	//the pool of numbers has to be similarly randomized, but with one less number, as the desert must map to an impossible dice roll
	std::vector<int> tileNumberPool = {8, 8, 9, 9, 10, 10, 11, 11, 12, 6, 6, 5, 5, 4, 4, 3, 3, 2};
	std::random_shuffle(tileNumberPool.begin(), tileNumberPool.end() );
	for(int i = 0; i < tileTypePool.size(); i++){
		if(tileTypePool[i] == NO_RESOURCE){
			tileNumberPool.insert(tileNumberPool.begin() + i, 0);
			break;
		}
	}
	//both vectors should have 19 randomized elements with 0 in the same place in both;
	for(int i = 0; i < 19; i++){
		this->allTiles.push_back(Tile t = {i, tileTypePool[i], tileNumberPool[i]});
	}//tiles should be allocated now, though not tied to anything else through relationships

	//need to initialize all of the roads now
	for(int i = 0; i < 72; i++){
		this->allRoads.push_back(Road r = {i, 0});
	}

	//nodes too
	for(int i = 0; i < 54; i++){
		this->allNodes.push_back(Node n = {i, 0, 0});
	}
	
}