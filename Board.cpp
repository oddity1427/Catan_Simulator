#ifndef BOARD_CPP_FLAG
#define BOARD_CPP_FLAG

#include "Board.hpp"
#include <iterator>
#include <algorithm>
#include <iostream>

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
	std::vector<int> tr_v_4 = {-1,	0,	1}; 	tile2roadVectors.push_back(tr_v_4);
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
		
		masterTiles[std::vector<int>(3,0)] = ((new Tile(std::vector<int>(3,0))));
		
		Tile * origin = (masterTiles[std::vector<int>(3,0)]);
		std::vector<Tile *> oldLeaves;
		std::vector<Tile *> newLeaves;
		oldLeaves.push_back(origin);

		if(param >= 1){
			for (std::vector<int> dir : tile2tileVectors){
				for(int i = 1; i <= param ; i++){	
					for(Tile * old : oldLeaves){
						std::vector<int> temp = addVect(old->getID(), dir);
						masterTiles[temp] = ((new Tile(temp)));
						newLeaves.push_back(masterTiles[temp]);
					}
					if(i > 1){
						std::vector<int> temp = addVect(tileTileClockDir(dir), (oldLeaves[oldLeaves.size() - 1])->getID());
						masterTiles[temp] = ((new Tile(temp)));
						newLeaves.push_back(masterTiles[temp]);	
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
	fillNodes();
	fillRoads();
}

void Board::buildBoard(std::vector<int> xcoor, std::vector<int> ycoor, std::vector<int> zcoor){
	
	std::vector<std::vector<int>> ordered;
	for(int i = 0; i < xcoor.size(); i++){
		std::vector<int> temp;
		temp.push_back(xcoor[i]);
		temp.push_back(ycoor[i]);
		temp.push_back(zcoor[i]);
		ordered.push_back(temp);
	}

	std::vector<std::vector<int>> toNext;
	std::vector<int> distance;

	for(int findFrom = 0; findFrom < ordered.size() - 1; findFrom++){
		std::vector<std::vector<int>> candidates;
		for(int i = 0; i < 6; i++ ){
			candidates.push_back(ordered[findFrom]);
		}
		bool foundNext = false;
		int countDist = 0;
		while(!foundNext){
			countDist++;
			for(int dir = 0; dir < 6; dir++){
				candidates[dir] = addVect(candidates[dir], tile2tileVectors[dir]);
				if(ordered[findFrom + 1] == candidates[dir]){
					toNext.push_back(tile2tileVectors[dir]);
					distance.push_back(countDist);
					foundNext = true;
				}

			}
		}
	}

	std::vector<std::vector<int>> candidates;
		for(int i = 0; i < 6; i++ ){
			candidates.push_back(ordered[ordered.size() - 1]);
		}
		bool foundNext = false;
		int countDist = 0;
		while(!foundNext){
			countDist++;
			for(int dir = 0; dir < 6; dir++){
				candidates[dir] = addVect(candidates[dir], tile2tileVectors[dir]);
				if(ordered[0] == candidates[dir]){
					toNext.push_back(tile2tileVectors[dir]);
					distance.push_back(countDist);
					foundNext = true;
				}
			}
		}
	

	for(int i = 0; i < distance.size(); i++){
		createTileLine(ordered[i], toNext[i], distance[i]);
	}

	if(masterTiles.find({0,0,0}) != masterTiles.end()){
		std::cout << "build failed; origin in perimeter of board\n";

	}else{
		if(masterTiles.size() <= 1000){
			fillTiles({0,0,0});
		}else{
			std::cout << "build failed; origin outside of board or board size > 1000\n";
		}
		std::cout << masterTiles.size() << "\n";		
	}
	//TODO:
	// use found, and toTHis vectors to step through the perimeter of the board
	// 	add the corresponding tiles to masterTiles


	// start at the origin: must be inside
	// create every tile next to it if it does not exist
	// tell every node created to create nodes next to it if they do not exist.
	// the board will now be populated
}

std::vector<int> Board::addVect(std::vector<int> * vec1, std::vector<int> * vec2){
	std::vector<int> output;
	for(int i = 0; i < 3; i++){
		output.push_back((*vec1)[i] + (*vec2)[i]);
	}
	return output;
}

std::vector<int> Board::addVect(std::vector<int>  vec1, std::vector<int>  vec2){
	std::vector<int> output;
	for(int i = 0; i < 3; i++){
		output.push_back((vec1)[i] + (vec2)[i]);
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

void Board::fillRoads(){
	//TODO::create this algorithm
}

void Board::fillNodes(){
	//TODO::create this algorithm 
}

void Board::printVect(std::vector<int> in){
	for(int i = 0; i < in.size(); i++){
		std::cout << in[i] << ", ";
	}
	std::cout << " ";
}

//distance is the distance to the next tile, including the end tile. This creates the current tile, but not the destination
void Board::createTileLine(std::vector<int> start, std::vector<int> dir, int dist){
	std::vector<int> current = start;
	for(int i = 0; i < dist; i++){
		masterTiles[current] = new Tile(current);
		current = addVect(current, dir);
	}
}

void Board::fillTiles(std::vector<int> coor){
	if(masterTiles.find(coor) == masterTiles.end()){
		masterTiles[coor] = new Tile(coor);
		for(int i = 0; i < 6; i++){
			fillTiles(addVect(coor, tile2tileVectors[i]));
		}
	}
}

#endif