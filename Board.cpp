#ifndef BOARD_CPP_FLAG
#define BOARD_CPP_FLAG

#include "Board.hpp"
#include <iterator>
#include <algorithm>

Board::Board(){};

void Board::buildBoard(){

}

void Board::buildBoard(int type, int param){
	if(type == STANDARD){
		if(param == STANDARD){
			//TODO: figure out what the right call to regular is
		}else if(param == SIX_PLAYER){
			//TODO: figure out what the coordinates for the tiles in the six player game are and call that constructor here
		}
	}else if(type == REGULAR){
		//TODO: logic for creating a regular board here;
	}
}

void Board::buildBoard(std::vector<int> xcoor, std::vector<int> ycoor, std::vector<int> zcoor){
	//TODO: this logic is going to be a bit more complicated than the others
}

#endif