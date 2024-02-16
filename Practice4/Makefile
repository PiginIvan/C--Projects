CXX = g++
CXXFLAGS = -g -O
INCLUDE = include

all: main
clean:
	del -f main *.o
main: main.o DynArray.o Vector3D.o
	$(CXX) $(CXXFLAGS) -o $@ $^

main.o:
	$(CXX) $(CXXFLAGS) -I $(INCLUDE) -c main.cpp

DynArray.o:
	$(CXX) $(CXXFLAGS) -I $(INCLUDE) -c src/DynArray.cpp

Vector3D.o:
	$(CXX) $(CXXFLAGS) -I $(INCLUDE) -c src/Vector3D.cpp

.PHONY: all clean