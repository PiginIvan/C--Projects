#define TASK2

#ifdef TASK1
#include <iostream>
#include <vector>
#include "Shape.hpp"
#include <algorithm>

int main() {
    int curID = 0;
    int numberOfFigures;
    std::cout << "Enter number of figures: ";
    std::cin >> numberOfFigures;
    std::vector<Shape*> shapes;
    initShapes(curID, numberOfFigures, shapes);
    printShapes(numberOfFigures, shapes);
    sort(shapes.begin(), shapes.end(), [](const Shape *a, const Shape *b){ return a->countPerimeter() > b->countPerimeter(); });
    printShapes(numberOfFigures, shapes);
    for(int i = 0; i < numberOfFigures; i++) delete shapes[i];
    return 0;
}

#endif

#ifdef TASK2
#include <iostream>
#include <vector>
#include "Piece.hpp"
#include <string>



int main() {
    char curColor = 'w';
    bool winFlag = false;
    std::vector<std::vector<Piece*>> board(8, std::vector<Piece*>(8));
    initBoard(board);
    printBoard(board);
    while(true) {
        std::string line;
        char stCol, endCol;
        int stIntRow, stIntCol, endIntRow, endIntCol; 
        std::cout << "Enter move in format('e2e4') or 'exit' to end: ";
        std::cin >> line;
        if(line == "exit") break;
        stCol = line[0]; endCol = line[2];
        stIntCol = convert(line[0]);
        endIntCol = convert(line[2]);
        stIntRow = line[1] - '0';
        endIntRow = line[3] - '0';
        if(8 - stIntRow < 0 || 8 - stIntRow > 7 || stIntCol < 0 || stIntCol > 7 || 
            8 - endIntRow < 0 || 8 - endIntRow > 7 || endIntCol < 0 || endIntCol > 7 
            || !board[8 - stIntRow][stIntCol]) { std::cout << "Incorrect indices for move" << std::endl; continue; 
        }
        if(board[8 - stIntRow][stIntCol]->move(8 - endIntRow, endIntCol, board, curColor, winFlag)) {
            if(curColor == 'w') curColor = 'b';
            else curColor = 'w';
        }
        if(winFlag) {
            std::cout << "Game is over!";
            break;
        }
        printBoard(board);
    }
    return 0;
}

#endif