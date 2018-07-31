#ifndef PLAYER_HPP_FLAG
#define PLAYER_HPP_FLAG

//There are only ever four players.
//updated with a null version so that roads( and others ) can be created but unowned
int const NO_PLAYER 	= 0;
int const PLAYER_RED 	= 1;
int const PLAYER_BLUE 	= 2;
int const PLAYER_WHITE 	= 3;
int const PLAYER_ORANGE = 4;

//right now there is not much to players other than that they exist
//this will just be used currently so that buildings and roads can have owners
//players will be able to do more things in the future, but this is not necessary right now
//I may actually later make this a parent of derived human/cpu players, but that will come later
struct Player{

	int color;
	Player(int);

};

#endif