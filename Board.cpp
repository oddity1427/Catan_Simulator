#ifndef BOARD_CPP_FLAG
#define BOARD_CPP_FLAG

#include "Board.hpp"
#include <iterator>
#include <algorithm>

Board::Board(){};

void Board::buildBoard(){

}

void Board::buildBoard(int type, int param){

//each of the following reference vector arrays is actually just 3 basis vectors mirrored, but it will be simpler to treat them as discrete directions.
//The coordinate system that I am using is shown in hexCoordinates.png
	//really it is a single triangular grid that all possible entities sit on.
	//This ensures unique ids but is not useful to understand because there are 3 separate types of entites sitting on disparate places.

//define the relative positions of a node from a tile at 0,0,0
	//starting at the vertical vector and moving clockwise
std::vector<std::vector<int>> tile2nodeVectors;
	std::vector<int> tn_v_0 = {1,	-1,	1}; 	tile2nodeVectors.push_back(tn_v_0);
	std::vector<int> tn_v_1 = {1,	-1,	-1}; 	tile2nodeVectors.push_back(tn_v_1);
	std::vector<int> tn_v_2 = {1,	1,	-1}; 	tile2nodeVectors.push_back(tn_v_2);
	std::vector<int> tn_v_3 = {-1,	1,	-1}; 	tile2nodeVectors.push_back(tn_v_3);
	std::vector<int> tn_v_4 = {-1,	1,	-1}; 	tile2nodeVectors.push_back(tn_v_4);
	std::vector<int> tn_v_5 = {-1,	-1,	1}; 	tile2nodeVectors.push_back(tn_v_5);

//define the relative positions of a road from a tile at 0,0,0
//roads are midpoints between tiles so this will also serve as a relative position between tiles, after multiplying by two.
//starting at the 1 o'clock position and moving clockwise
std::vector<std::vector<int>> tile2roadVectors;
	std::vector<int> tr_v_0 = {1,	-1,	0};		tile2roadVectors.push_back(tr_v_0);
	std::vector<int> tr_v_1 = {1,	0,	-1}; 	tile2roadVectors.push_back(tr_v_1);
	std::vector<int> tr_v_2 = {0,	1,	-1}; 	tile2roadVectors.push_back(tr_v_2);
	std::vector<int> tr_v_3 = {-1,	1,	0}; 	tile2roadVectors.push_back(tr_v_3);
	std::vector<int> tr_v_4 = {1,	0,	1}; 	tile2roadVectors.push_back(tr_v_4);
	std::vector<int> tr_v_5 = {0,	-1,	1}; 	tile2roadVectors.push_back(tr_v_5);


	if(type == STANDARD){
		if(param == STANDARD){
			Board::buildBoard(REGULAR, 2);
		}else if(param == SIX_PLAYER){
			//TODO: figure out what the coordinates for the tiles in the six player game are and call that constructor here
		}
	}else if(type == REGULAR){
		//TODO: logic for creating a regular board here;
		//notes: enumerate tiles and then create the corresponding roads, which will create the requisite nodes, which will then fill in the tiles that they are attached to
		
	}
}

void Board::buildBoard(std::vector<int> xcoor, std::vector<int> ycoor, std::vector<int> zcoor){
	//TODO: this logic is going to be a bit more complicated than the others
}

#endif