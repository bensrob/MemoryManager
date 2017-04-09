MAKEFLAGS+=-j4
CXXFLAGS+=-O0 -Wall -Wextra -pedantic -pthread -g	
CC=g++ -o $@	
DEP=*.h
OBJ=$(patsubst %.cpp,%.o,$(wildcard *.cpp))

main:	$(OBJ)
	$(CC) $(CXXFLAGS) $(OBJ)

%.o: 	%.cpp $(DEP)
	$(CC) $(CXXFLAGS) -include stl.h $< -c

stl:
	g++ $(CXXFLAGS) stl.h

clean:
	sudo rm main -f
	sudo rm *.o -f
	@+make

