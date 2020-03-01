CC=g++
CFLAGS=-std=c++17 -W -Wall -DW=4 -DH=4
LINK=-O3
SRC=main.cpp 
OBJ=$(SRC:.cpp=.o)

%.o:	%.cpp
	$(CC) -c $(CFLAGS) $<

game: 	$(OBJ)
	$(CC) $(LINK) $(OBJ) -o $@

clean:
	rm *.o game
