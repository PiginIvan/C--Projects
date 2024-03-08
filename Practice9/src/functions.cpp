#include "functions.hpp"
#include "LinkedList.hpp"
#include <random>
#include <chrono>
#include <iostream>

void createVectorAndPushBackTime() {
    std::cout << "Create empty vector and fill it with push_back:" << std::endl;
    std::chrono::steady_clock clock;
    for(int N = 1; N < 20; N++) {
        auto start = clock.now();
        std::vector<int> vec(N);
        for(int elem = 0; elem < N; elem++) {
            vec.push_back(elem);
        }
        auto finish = clock.now();
        std::chrono::duration<double, std::ratio<1, 1000000>> func_runtime = finish - start;
        std::cout << "Size: " << N << " Time: " << func_runtime.count() << " microseconds" << std::endl;
    }
}

void createVectorAndInsertTime() {
    std::cout << "Create empty vector and fill it with insert(vec.begin()):" << std::endl;
    std::chrono::steady_clock clock;
    for(int N = 1; N < 20; N++) {
        auto start = clock.now();
        std::vector<int> vec(N);
        for(int elem = 0; elem < N; elem++) {
            vec.insert(vec.begin(), elem);
        }
        auto finish = clock.now();
        std::chrono::duration<double, std::ratio<1, 1000000>> func_runtime = finish - start;
        std::cout << "Size: " << N << " Time: " << func_runtime.count() << " microseconds" << std::endl;
    }
}

void randomInsertInFilledVectorTime() {
    std::cout << "Insert one element in random position in filled vector:" << std::endl;
    std::chrono::steady_clock clock;
    for(int N = 1; N < 20; N++) {
        std::vector<int> vec(N + 1);
        for(int elem = 0; elem < N; elem++) {
            vec.push_back(elem);
        }
        std::mt19937 mt_engine;
        mt_engine.seed(std::chrono::system_clock::now().time_since_epoch().count());
        std::uniform_int_distribution<int> dist(0, N);
        auto start = clock.now();
        vec.insert(vec.begin() + dist(mt_engine), dist(mt_engine));
        auto finish = clock.now();
        std::chrono::duration<double, std::ratio<1, 1000000>> func_runtime = finish - start;
        std::cout << "Size: " << N << " Time: " << func_runtime.count() << " microseconds" << std::endl;
    }
}

void createListAndPushBackTime() {
    std::cout << "Create empty LinkedList and fill it with push_back:" << std::endl;
    std::chrono::steady_clock clock;
    for(int N = 1; N < 20; N++) {
        auto start = clock.now();
        LinkedList<int> list;
        for(int elem = 0; elem < N; elem++) {
            list.push_back(elem);
        }
        auto finish = clock.now();
        std::chrono::duration<double, std::ratio<1, 1000000>> func_runtime = finish - start;
        std::cout << "Size: " << N << " Time: " << func_runtime.count() << " microseconds" << std::endl;
    }
}

void createListAndInsertTime() {
    std::cout << "Create empty LinkedList and fill it with push_front:" << std::endl;
    std::chrono::steady_clock clock;
    for(int N = 1; N < 20; N++) {
        auto start = clock.now();
        LinkedList<int> list;
        for(int elem = 0; elem < N; elem++) {
            list.push_front(elem);
        }
        auto finish = clock.now();
        std::chrono::duration<double, std::ratio<1, 1000000>> func_runtime = finish - start;
        std::cout << "Size: " << N << " Time: " << func_runtime.count() << " microseconds" << std::endl;
    }
}

void randomInsertInFilledLinkedListTime() {
    std::cout << "Insert one element in random position in filled LinkedList:" << std::endl;
    std::chrono::steady_clock clock;
    for(int N = 1; N < 20; N++) {
        LinkedList<int> list;
        for(int elem = 0; elem < N; elem++) {
            list.push_back(elem);
        }
        std::mt19937 mt_engine;
        mt_engine.seed(std::chrono::system_clock::now().time_since_epoch().count());
        std::uniform_int_distribution<int> dist(0, N);
        auto start = clock.now();
        list.insert(dist(mt_engine), dist(mt_engine));
        auto finish = clock.now();
        std::chrono::duration<double, std::ratio<1, 1000000>> func_runtime = finish - start;
        std::cout << "Size: " << N << " Time: " << func_runtime.count() << " microseconds" << std::endl;
    }
}
void initBoard(double& d, int& M, int& K, double& w) {
    std::cout << "Enter the pin spacing (d): "; std::cin >> d;
    std::cout << "Enter the height (M): "; std::cin >> M;
    std::cout << "Enter the number of cells (K): "; std::cin >> K;
    std::cout << "Enter the width of a cell (w): "; std::cin >> w;
}

void fillBoard(int M, int K, double w, double d, std::vector<int>& board) {
    std::mt19937 mt_engine(std::chrono::system_clock::now().time_since_epoch().count());
    std::uniform_int_distribution<> dist(0, 1);
    double x = 0.0;
    for (int i = 0; i < 100; i++) {
        x = 0.0;
        for (int j = 0; j < M; j++) { 
            if (x == K * w / 2.0) x -= d;               
            else if (x == -K * w / 2.0) x += d;
            else x += (dist(mt_engine) * 2 - 1) * d;                                
        }
        int index = floor((x + K * w / 2.0) / w);
        if (index >= 0 && index < K) board[index]++;
    }
}

void printBoard(std::vector<int> board) {
    for(int i = 0; i < board.size(); i++) {
        for(int j = 0; j < board[i]; j++) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }
}
