//Right now just being used to check if all of the files will compile or if I've done something really wrong


#include "Board.hpp"
#include <vector>
#include <iostream>

int main(){
	Board b;
	std::vector<int> x;
	std::vector<int> y;
	std::vector<int> z;
	for(int i = 0; i < 6; i++){
		x.push_back(b.tile2tileVectors[i][0]);
		y.push_back(b.tile2tileVectors[i][1]);
		z.push_back(b.tile2tileVectors[i][2]);
	} 
	std::cout << x.size() << "\n" << "buildboard below \n";

	b.buildBoard(x,y,z);
	
	return 0;
}