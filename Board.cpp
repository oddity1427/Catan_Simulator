#ifndef BOARD_CPP_FLAG
#define BOARD_CPP_FLAG

#include "Board.hpp"
#include <iterator>
#include <algorithm>

Board::Board(){
	//each of the following reference vector arrays is actually just 3 basis vectors mirrored, but it will be simpler to treat them as discrete directions.
//The coordinate system that I am using is shown in hexCoordinates.png
	//really it is a single triangular grid that all possible entities sit on.
	//This ensures unique ids but is not useful to understand because there are 3 separate types of entites sitting on disparate places.

//define the relative positions of a node from a tile at 0,0,0
	//starting at the vertical vector and moving clockwise
	std::vector<int> tn_v_0 = {1,	-1,	1}; 	tile2nodeVectors.push_back(tn_v_0);
	std::vector<int> tn_v_1 = {1,	-1,	-1}; 	tile2nodeVectors.push_back(tn_v_1);
	std::vector<int> tn_v_2 = {1,	1,	-1}; 	tile2nodeVectors.push_back(tn_v_2);
	std::vector<int> tn_v_3 = {-1,	1,	-1}; 	tile2nodeVectors.push_back(tn_v_3);
	std::vector<int> tn_v_4 = {-1,	1,	-1}; 	tile2nodeVectors.push_back(tn_v_4);
	std::vector<int> tn_v_5 = {-1,	-1,	1}; 	tile2nodeVectors.push_back(tn_v_5);

//define the relative positions of a road from a tile at 0,0,0
//roads are midpoints between tiles so this will also serve as a relative position between tiles, after multiplying by two.
//starting at the 1 o'clock position and moving clockwise
	std::vector<int> tr_v_0 = {1,	-1,	0};		tile2roadVectors.push_back(tr_v_0);
	std::vector<int> tr_v_1 = {1,	0,	-1}; 	tile2roadVectors.push_back(tr_v_1);
	std::vector<int> tr_v_2 = {0,	1,	-1}; 	tile2roadVectors.push_back(tr_v_2);
	std::vector<int> tr_v_3 = {-1,	1,	0}; 	tile2roadVectors.push_back(tr_v_3);
	std::vector<int> tr_v_4 = {1,	0,	1}; 	tile2roadVectors.push_back(tr_v_4);
	std::vector<int> tr_v_5 = {0,	-1,	1}; 	tile2roadVectors.push_back(tr_v_5);

//explicitly create the tiletotile vector
	for (std::vector<int> v : tile2roadVectors){
		tile2tileVectors.push_back(addVect(&v, &v));
	}
};

void Board::buildBoard(){
	buildBoard(STANDARD, STANDARD);
}

void Board::buildBoard(int type, int param){




	if(type == STANDARD){
		if(param == STANDARD){
			buildBoard(REGULAR, 2);
		}else if(param == SIX_PLAYER){
			//TODO: figure out what the coordinates for the tiles in the six player game are and call that constructor here
		}
	}else if(type == REGULAR){
		//build out the tiles; each direction makes a tree with one split on the rightmost brach after the first nodes are created
		

		//always create center node
		
		masterTiles.push_back(*(new Tile(std::vector<int>(3,0))));
		Tile * origin = &(masterTiles[0]);
		std::vector<Tile *> oldLeaves;
		std::vector<Tile *> newLeaves;
		oldLeaves.push_back(origin);

		if(param >= 1){
			for (std::vector<int> dir : tile2tileVectors){
				for(int i = 1; i <= param ; i++){
					for(Tile * old : oldLeaves){
						masterTiles.push_back(*(new Tile(addVect(old->getID(), dir))));
						newLeaves.push_back(&masterTiles[masterTiles.size() - 1]);
					}
					if(i > 1){
						masterTiles.push_back(*(new Tile(addVect(tileTileClockDir(dir), (oldLeaves[oldLeaves.size() - 1])->getID()))));
						newLeaves.push_back(&masterTiles[masterTiles.size() - 1]);	
					}
					oldLeaves = newLeaves;
					newLeaves.clear();
				}
				//reset for the next direction
				oldLeaves.clear();
				newLeaves.clear();
				oldLeaves.push_back( origin);
			}
		}
		
	}
}

void Board::buildBoard(std::vector<int> xcoor, std::vector<int> ycoor, std::vector<int> zcoor){
	//TODO: this logic is going to be a bit more complicated than the others
}

std::vector<int> Board::addVect(std::vector<int> * vec1, std::vector<int> * vec2){
	std::vector<int> output;
	for(int i = 0; i < 3; i++){
		output.push_back((*vec1)[i] + (*vec1)[i]);
	}
	return output;
}

std::vector<int> Board::addVect(std::vector<int>  vec1, std::vector<int>  vec2){
	std::vector<int> output;
	for(int i = 0; i < 3; i++){
		output.push_back((vec1)[i] + (vec1)[i]);
	}
	return output;
}

//returns the direction clockwise from the direction inputted from the tile2tileVectors vect
std::vector<int> Board::tileTileClockDir(std::vector<int> current){
	for(int i = 0; i < 5; i++){
		if(current == tile2tileVectors[i]){
			return tile2tileVectors[i+1];
		}
	}
	//must then match the last dir, so return the first
	return tile2tileVectors[0];
}
#endif