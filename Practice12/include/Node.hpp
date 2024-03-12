#ifndef NODE_HPP
#define NODE_HPP
#include <unordered_map>
#include <vector>
#include <string>

class Node {
public:
	int id;
    std::vector<int> adj;
    std::unordered_map<std::string, int> m;

	Node();
	Node(int curId);

    void addNeighbour(int curId);
    void insert(std::string key, int val);
    void printNode();

};

#endif