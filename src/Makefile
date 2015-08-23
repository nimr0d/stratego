

#objects = $(patsubst %.cpp, %.o, $(wildcard *.cpp))
objects = $(wildcard *.cpp)
#main.o Board.o Piece.o Move.o BoardIO.o
CFLAGS  = -std=c++11 -O3

all: $(objects)
	g++ $(objects) -o stratego $(CFLAGS)

main.o : main.cpp
	g++ -c main.cpp $(CFLAGS)

Board.o : Board.cpp Board.hpp
	g++ -c Board.cpp $(CFLAGS)

Move.o : Move.cpp Move.hpp
	g++ -c Move.cpp $(CFLAGS)

BoardIO.o : BoardIO.cpp BoardIO.hpp
	g++ -c BoardIO.cpp $(CFLAGS)

Piece.o : Piece.cpp Piece.hpp
	g++ -c Piece.cpp $(CFLAGS)

clean: 
	mv *.o ../build/
