#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP
#include <vector>
#include <chrono>
#include <random>

void createVectorAndPushBackTime();
void createVectorAndInsertTime();
void randomInsertInFilledVectorTime();
void createListAndPushBackTime();
void createListAndInsertTime();
void randomInsertInFilledLinkedListTime();

void initBoard(double& d, int& M, int& K, double& w);
void fillBoard(int M, int K, double w, double d, std::vector<int>& board);
void printBoard(std::vector<int> board);

#endif