CXX = g++
CXXFLAGS = -g -O
INCLUDE = include

all: main
clean:
	del -f main *.o
main: main.o sorting.o
	$(CXX) $(CXXFLAGS) -o $@ $^

main.o:
	$(CXX) $(CXXFLAGS) -I $(INCLUDE) -c main.cpp

sorting.o:
	$(CXX) $(CXXFLAGS) -I $(INCLUDE) -c src/sorting.cpp

.PHONY: all clean