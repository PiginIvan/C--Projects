#ifndef GRAPH_HPP
#define GRAPH_HPP
#include "Node.hpp"
#include <functional>

class Graph {
public:
    std::vector<Node*> nodes;

    Graph();

    void insert(Node* curNode);
    void printGraph();
    void BFS(const std::function<void(const Node&)>& func, int index);
    void DFS(const std::function<void(const Node&)>& func, int index, std::vector<bool>& visited);
};

#endif