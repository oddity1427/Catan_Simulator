#ifndef _PLAYER_HPP
#define _PLAYER_HPP

//There are only ever four players.
int const PLAYER_RED 	= 0;
int const PLAYER_BLUE 	= 1;
int const PLAYER_WHITE 	= 2;
int const PLAYER_ORANGE = 3;

//right now there is not much to players other than that they exist
//this will just be used currently so that buildings and roads can have owners
//players will be able to do more things in the future, but this is not necessary right now
//I may actually later make this a parent of derived human/cpu players, but that will come later
struct Player{

	int color;

};

#endif