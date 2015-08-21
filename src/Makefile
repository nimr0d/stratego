all: main.o Board.o Piece.o Move.o BoardIO.o
	g++ main.o Board.o Piece.o Move.o BoardIO.o -o stratego -std=c++11 -O3

main.o : main.cpp
	g++ -c main.cpp

Board.o : Board.cpp
	g++ -c Board.cpp -std=c++11

Move.o : Move.cpp
	g++ -c Move.cpp -std=c++11

BoardIO.o : BoardIO.cpp
	g++ -c BoardIO.cpp -std=c++11

Piece.o : Piece.cpp
	g++ -c Piece.cpp -std=c++11


auto: 
	make bring_back; make; make clean;

clean: 
	mv *.o ../build/

bring_back:
	mv ../build/*.o .
