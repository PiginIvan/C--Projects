CXX = g++
CXXFLAGS = -g -O
INCLUDE = include

all: main
clean:
	del -f main *.o
main: main.o functions.o 
	$(CXX) $(CXXFLAGS) -o $@ $^

main.o:
	$(CXX) $(CXXFLAGS) -I $(INCLUDE) -c main.cpp

functions.o:
	$(CXX) $(CXXFLAGS) -I $(INCLUDE) -c src/functions.cpp

.PHONY: all clean