CXX = g++
CXXFLAGS = -g -O
INCLUDE = include

all: main
clean:
	del -f main *.o
main: main.o DynArray.o Queue.o
	$(CXX) $(CXXFLAGS) -o $@ $^

main.o:
	$(CXX) $(CXXFLAGS) -I $(INCLUDE) -c main.cpp

DynArray.o:
	$(CXX) $(CXXFLAGS) -I $(INCLUDE) -c src/DynArray.cpp

Queue.o:
	$(CXX) $(CXXFLAGS) -I $(INCLUDE) -c src/Queue.cpp

.PHONY: all clean