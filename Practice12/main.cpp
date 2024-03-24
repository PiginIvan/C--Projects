#include "Graph.hpp"
#include <iostream>
#include <memory>

int main() {
    Graph town = Graph();

    int curId = 0;
    std::shared_ptr<Node> zero = std::make_shared<Node>(curId++);
    zero->insert("NN", 5);
    zero->insert("Dzerhinsk", 1);
    zero->addNeighbour(1);
    zero->addNeighbour(3);
    std::shared_ptr<Node> one = std::make_shared<Node>(curId++);
    one->insert("Kstovo", 45);
    one->insert("Dzerhinsk", 2);
    one->addNeighbour(0);
    one->addNeighbour(4);
    one->addNeighbour(3);
     std::shared_ptr<Node> two = std::make_shared<Node>(curId++);
    two->insert("Moscow", -77);
    two->insert("SpB", 22);
    two->addNeighbour(3);
     std::shared_ptr<Node> three = std::make_shared<Node>(curId++);
    three->insert("NN", 7);
    three->insert("Kazan", 1111);
    three->addNeighbour(0);
    three->addNeighbour(1);
    three->addNeighbour(2);
     std::shared_ptr<Node> four = std::make_shared<Node>(curId++);
    four->insert("Sochi", 7);
    four->addNeighbour(1);

    town.insert(zero.get()); town.insert(one.get()); town.insert(two.get()); town.insert(three.get()); town.insert(four.get());

    std::string key;
    std::cout << "Input key, that you want to find:" << std::endl;
    std::cin >> key;
    
    auto func = [key](const Node& node) {
        if (node.getM().find(key) != node.getM().end()) {
            std::cout << "Node ID: " << node.getID() << ", Key: " << key << ", Value: " << node.getM().at(key) << "\n";
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