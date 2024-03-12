#include "Graph.hpp"
#include <iostream>

int main() {
    Graph town = Graph();

    int curId = 0;
    Node* zero = new Node(curId++);
    zero->insert("NN", 5);
    zero->insert("Dzerhinsk", 1);
    zero->addNeighbour(1);
    zero->addNeighbour(3);
    Node* one = new Node(curId++);
    one->insert("Kstovo", 45);
    one->insert("Dzerhinsk", 2);
    one->addNeighbour(0);
    one->addNeighbour(4);
    one->addNeighbour(3);
    Node* two = new Node(curId++);
    two->insert("Moscow", -77);
    two->insert("SpB", 22);
    two->addNeighbour(3);
    Node* three = new Node(curId++);
    three->insert("NN", 7);
    three->insert("Kazan", 1111);
    three->addNeighbour(0);
    three->addNeighbour(1);
    three->addNeighbour(2);
    Node* four = new Node(curId++);
    four->insert("Sochi", 7);
    four->addNeighbour(1);

    town.insert(zero); town.insert(one); town.insert(two); town.insert(three); town.insert(four);

    std::string key;
    std::cout << "Input key, that you want to find:" << std::endl;
    std::cin >> key;
    
    auto func = [key](const Node& node) {
        if (node.m.find(key) != node.m.end()) {
            std::cout << "Node ID: " << node.id << ", Key: " << key << ", Value: " << node.m.at(key) << "\n";
        }
    };
    
    town.printGraph();
    std::cout << "BFS result:" << std::endl;
    town.BFS(func, 4);
    std::vector<bool> visited(5);
    std::cout << "DFS result:" << std::endl;
    town.DFS(func, 2, visited);

    return 0;
}