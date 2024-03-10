#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP
#include <vector>
#include <string>

void LeftRotation();
std::vector<int> rotateLeft(int d, std::vector<int> arr);

void VectorErase();

void DequeSTL();
void printKMax(std::vector<int> arr, int n, int k);

void EqualStacks();
int find_height(std::vector<int> arr);
int find_max(int f, int s, int t);
int equalStacks(std::vector<int> h1, std::vector<int> h2, std::vector<int> h3);

void BalancedBrackets();
std::string isBalanced(std::string s);

void ComponentsInAGraph();
int find_len(int pos, std::vector<std::vector<int>>& edges, std::vector<int>& visited);
std::vector<int> componentsInGraph(std::vector<std::vector<int>> gb);

#endif


