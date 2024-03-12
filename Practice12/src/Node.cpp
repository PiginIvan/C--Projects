#include "Node.hpp"
#include <iostream>

Node::Node() : id(0), adj(std::vector<int>()), m(std::unordered_map<std::string, int>()) { }

Node::Node(int curId) : id(curId), adj(std::vector<int>()), m(std::unordered_map<std::string, int>()) { }

void Node::addNeighbour(int curId) { adj.push_back(curId); }

void Node::insert(std::string key, int val) { m[key] = val; }

void Node::printNode() {
    std::cout << "CurNodeId is: " << id << std::endl;
    std::cout << "CurKeyValues are: " << std::endl;
    for(auto& x : m) {
        std::cout << x.first << " " << x.second << std::endl;
    }
    std::cout << "CurNeighbours are: " << std::endl;
    for(auto& x : adj) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
}