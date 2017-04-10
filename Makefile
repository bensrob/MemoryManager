MAKEFLAGS+=-j4
CXXFLAGS+=-O0 -Wall -Wextra -pedantic -pthread -g -fno-sized-deallocation	
CC=g++ $(CXXFLAGS) 	
DEP=*.h

memman.o: memman.cpp memman.h
	$(CC) $< -c -o $@
clean:
	rm memman.o
	@+make

