
CC=g++

CFLAGS=-c -std=c++11

all: player

player: main.o player.o json.o GameState.o Ranking.o
	$(CC) main.o player.o json.o GameState.o Ranking.o -o player

main.o:
	$(CC) $(CFLAGS) main.cpp

player.o: 
	$(CC) $(CFLAGS) player.cpp

GameState.o: 
	$(CC) $(CFLAGS) GameState.cpp

Ranking.o: 
	$(CC) $(CFLAGS) Ranking.cpp

json.o:
	$(CC) $(CFLAGS) json.cpp

clean:
	rm -rf *.o player
