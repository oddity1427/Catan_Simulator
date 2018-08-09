
OBJS 	= main.o Node.o Tile.o Player.o Road.o Board.o
CPPFLAGS 	= --std=c++11 -c
LDFLAGS	= --std=c++11 -o classTests

classTests: $(OBJS)
	g++ $(LDFLAGS) $(OBJS)
main.o: main.cpp Node.cpp Tile.cpp Player.cpp Road.cpp Board.cpp
	g++ $(CPPFLAGS) main.cpp Node.cpp Tile.cpp Player.cpp Road.cpp
Node.o: Node.hpp
	g++ $(CPPFLAGS) Node.cpp 
Tile.o: Tile.hpp
	g++ $(CPPFLAGS) Tile.cpp 
Player.o: Player.hpp Tile.hpp
	g++ $(CPPFLAGS) Player.cpp Tile.cpp
Road.o:  Road.hpp
	g++ $(CPPFLAGS) Road.cpp 
Board.o: Board.hpp Node.hpp Tile.hpp Road.hpp
	g++ $(CPPFLAGS) Board.cpp
clean: 
	rm -f core classTests $(OBJS)