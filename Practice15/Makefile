CXX = g++
CXXFLAGS = -g -O
INCLUDE = include

all: main
clean:
	del -f main *.o
main: main.o Piece.o Shape.o
	$(CXX) $(CXXFLAGS) -o $@ $^

main.o:
	$(CXX) $(CXXFLAGS) -I $(INCLUDE)/chess $(INCLUDE)/shape -c main.cpp

Piece.o:
	$(CXX) $(CXXFLAGS) -I $(INCLUDE)/chess -c src/chess/Piece.cpp

Shape.o:
	$(CXX) $(CXXFLAGS) -I $(INCLUDE)/shape -c src/shape/Shape.cpp

.PHONY: all clean