#ifndef GRAPH_HPP
#define GRAPH_HPP
#include "Node.hpp"
#include <functional>
#include "memory"

class Graph {
private:
    std::vector<std::shared_ptr<Node>> nodes;

public:
    Graph();

    void insert(Node* curNode);
    void printGraph();
    void BFS(const std::function<void(const Node&)>& func, int index);
    void DFS(const std::function<void(const Node&)>& func, int index, std::vector<bool>& visited);
};

#endif