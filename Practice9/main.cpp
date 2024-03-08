#include "functions.hpp"

#define TASK1

#ifdef TASK1

int main() {
    createVectorAndPushBackTime();
    createVectorAndInsertTime();
    randomInsertInFilledVectorTime();
    return 0;
}

#endif

#ifdef TASK2

int main() {
    createListAndPushBackTime();
    createListAndInsertTime();
    randomInsertInFilledLinkedListTime();
    return 0;
}

#endif

#ifdef TASK3
#include <vector>

int main() {
    double d, w;
    int M, K;
    initBoard(d, M, K, w);
    std::vector<int> board(K);
    fillBoard(M, K, w, d, board);
    printBoard(board);
    return 0;
}

#endif
