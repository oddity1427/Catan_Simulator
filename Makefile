
OBJS 	= main.o Node.o Tile.o Player.o Road.o
CPPFLAGS 	= --std=c++11 -c
LDFLAGS	= --std=c++11 -o classTests

classTests: $(OBJS)
	g++ $(LDFLAGS) $(OBJS)
main.o: main.cpp Node.cpp Tile.cpp Player.cpp Road.cpp
	g++ $(CPPFLAGS) main.cpp Node.cpp Tile.cpp Player.cpp Road.cpp
Node.o: Node.hpp
	g++ $(CPPFLAGS) Node.cpp 
Tile.o: Tile.hpp
	g++ $(CPPFLAGS) Tile.cpp 
Player.o: Player.hpp
	g++ $(CPPFLAGS) Player.cpp Tile.cpp
Road.o:  Road.hpp
	g++ $(CPPFLAGS) Road.cpp 
clean: 
	rm -f core classTests $(OBJS)