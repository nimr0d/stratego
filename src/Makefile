

objects = $(patsubst %.cpp, %.o, $(wildcard *.cpp))
#main.o Board.o Piece.o Move.o BoardIO.o

CFLAGS  = -std=c++11 -O3

all: $(objects)
	g++ $(objects) -o stratego $(CFLAGS)

#main.o : main.cpp
#	g++ -c main.cpp

Board.o : Board.cpp
	g++ -c Board.cpp $(CFLAGS)

Move.o : Move.cpp
	g++ -c Move.cpp $(CFLAGS)

BoardIO.o : BoardIO.cpp
	g++ -c BoardIO.cpp $(CFLAGS)

Piece.o : Piece.cpp
	g++ -c Piece.cpp $(CFLAGS)


auto: 
	make bring_back; make; make clean;

clean: 
	mv *.o ../build/

bring_back:
	mv ../build/*.o .
