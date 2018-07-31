//Right now just being used to check if all of the files will compile or if I've done something really wrong

#include "Node.hpp"
#include "Tile.hpp"
#include "Player.hpp"
#include "Road.hpp"
#include "Node.hpp"

int main(){
	Node n = new Node(1, Player(1));
	Tile t = new Tile(1);
	Road r = new Road(-1);
	
	return 0;
}