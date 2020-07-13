OBJS = roulette.o function.o playerlist.o
CC = g++
CFLAGS=-c -Wall -I./include

all: program

program: $(OBJS)
	$(CC) $(OBJS) -o program 

roulette.o:	./src/roulette.cpp 
	$(CC) $(CFLAGS) ./src/roulette.cpp
	
function.o: ./src/function.cpp ./include/function.h
	$(CC) $(CFLAGS) ./src/function.cpp

playerlist.o: ./src/playerlist.cpp ./include/playerlist.h
	$(CC) $(CFLAGS) ./src/playerlist.cpp


clean:
	@rm -rf program *.o 
