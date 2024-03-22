#include "Graph.hpp"
#include <iostream>
#include <queue>

Graph::Graph() : nodes(std::vector<Node*>()) { }

void Graph::insert(Node* curNode) { nodes.push_back(curNode); }

void Graph::printGraph() {
    for(int i = 0; i < nodes.size(); i++) {
        nodes[i]->printNode();
    }
    std::cout << std::endl;
}

void Graph::BFS(const std::function<void(const Node&)>& func, int index) {
    std::queue<int> q;
    std::vector<bool> visited(nodes.size());
    q.push(index);
    visited[index] = true;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        func(*nodes[cur]);
        
        for (int neighbor : nodes[cur]->getADJ()) {    
            if (!visited[neighbor]) {
                q.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }
}

void Graph::DFS(const std::function<void(const Node&)>& func, int index, std::vector<bool>& visited) {
    visited[index] = true;
    
    func(*nodes[index]);
 
    for (int neighbor : nodes[index]->getADJ()) {    
        if (!visited[neighbor]) {
            DFS(func, neighbor, visited);
        }
    }
}