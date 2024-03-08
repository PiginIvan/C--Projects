CXX = g++
CXXFLAGS = -g -O
INCLUDE = include

all: main
clean:
	del -f main *.o
main: main.o LinkedList.o Node.o functions.o
	$(CXX) $(CXXFLAGS) -o $@ $^

main.o:
	$(CXX) $(CXXFLAGS) -I $(INCLUDE) -c main.cpp

LinkedList.o:
	$(CXX) $(CXXFLAGS) -I $(INCLUDE) -c src/LinkedList.cpp

Node.o:
	$(CXX) $(CXXFLAGS) -I $(INCLUDE) -c src/Node.cpp

functions.o:
	$(CXX) $(CXXFLAGS) -I $(INCLUDE) -c src/functions.cpp

.PHONY: all clean