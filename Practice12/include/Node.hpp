#ifndef NODE_HPP
#define NODE_HPP
#include <unordered_map>
#include <vector>
#include <string>

class Node {
private:
    int id;
    std::vector<int> adj;
    std::unordered_map<std::string, int> m;

public:
	Node();
	Node(int curId);
    int getID() const;
    std::unordered_map<std::string, int> getM() const;
    std::vector<int> getADJ() const;
    void addNeighbour(int curId);
    void insert(std::string key, int val);
    void printNode();

};

#endif