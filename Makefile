
OBJS = main.o Node.o Tile.o Player.o Road.o

classTests: $(OBJS)
	g++ --std=c++11 -o classTests $(OBJS)
main.o: main.cpp Node.cpp Tile.cpp Player.cpp Road.cpp
	g++ --std=c++11 -c main.cpp Node.cpp Tile.cpp Player.cpp Road.cpp
Node.o: Node.cpp Node.hpp
	g++ --std=c++11 -c Node.cpp Node.hpp
Tile.o: Tile.cpp Tile.hpp
	g++ --std=c++11 -c Tile.cpp Tile.hpp
Player.o: Player.cpp Player.hpp
	g++ --std=c++11 -c Player.cpp Tile.cpp
Road.o: Road.cpp Road.hpp
	g++ --std=c++11 -c Road.cpp Road.hpp
clean: 
	rm -f core classTests $(OBJS)