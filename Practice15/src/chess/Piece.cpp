#include "Piece.hpp"
#include <iostream>

Piece& Piece::operator=(const Piece& other) {
    row = other.row;
    col = other.col;
    return *this;
}

void initBoard(std::vector<std::vector<Piece*>>& board) {
    board[0][0] = new Rook(0, 0, 'b');
    board[0][7] = new Rook(0, 7, 'b');
    board[7][0] = new Rook(7, 0, 'w');
    board[7][7] = new Rook(7, 7, 'w');

    board[0][1] = new Knight(0, 1, 'b');
    board[0][6] = new Knight(0, 6, 'b');
    board[7][1] = new Knight(7, 1, 'w');
    board[7][6] = new Knight(7, 6, 'w');

    board[0][2] = new Bishop(0, 2, 'b');
    board[0][5] = new Bishop(0, 5, 'b');
    board[7][2] = new Bishop(7, 2, 'w');
    board[7][5] = new Bishop(7, 5, 'w');

    board[0][3] = new Queen(0, 3, 'b');
    board[7][3] = new Queen(7, 3, 'w');

    board[0][4] = new King(0, 4, 'b');
    board[7][4] = new King(7, 4, 'w');

    for(int i = 0; i < 8; i++) {
        board[1][i] = new Pawn(1, i, 'b');
    }
    for(int i = 0; i < 8; i++) {
        board[6][i] = new Pawn(6, i, 'w');
    }
}

void printBoard(const std::vector<std::vector<Piece*>> board) {
    std::vector<char> columns = {' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};
    for(int i = 0; i < board.size(); i++) {
        std::cout << 8 - i << " ";
        for(int j = 0; j < board[0].size(); j++) {
            if(board[i][j] != nullptr) {
                board[i][j]->printPiece();
            }
            else {
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }
    for(int i = 0; i < 10; i++) {
        std::cout << columns[i];
    }
    std::cout << std::endl << std::endl;
}

Pawn::Pawn(int Row, int Col, char Color) {
    row = Row;
    col = Col;
    color = Color;
    symb = 'p';
}

bool Pawn::move(int endRow, int endCol, std::vector<std::vector<Piece*>>& board, char& curColor, bool& winFlag) {
    if(board[row][col]->getColor() != curColor || (board[endRow][endCol] != nullptr && board[endRow][endCol]->getColor() == curColor)) {
        std::cout << "Wrong piece color" << std::endl;
        return false;
    }
    if(color == 'b') {
        if(row == 1) {
            if(endRow - row >= 1 && endRow - row <= 2 && col == endCol && board[row + 1][col] == nullptr && board[row + 2][col] == nullptr) {
                if(board[endRow][endCol] != nullptr && board[endRow][endCol]->getSymb() == 'K') winFlag = true;
                board[endRow][endCol] = board[row][col];
                board[row][col] = nullptr;
                row = endRow;
                return true;
            }
        }
        if(endRow - row == 1 && col == endCol && board[endRow][endCol] == nullptr) {
            if(board[endRow][endCol] != nullptr && board[endRow][endCol]->getSymb() == 'K') winFlag = true;
            board[endRow][endCol] = board[row][col];
            board[row][col] = nullptr;
            row = endRow;
            return true;
        }
        if(endRow - row == 1 && (endCol - col == -1 || endCol - col == 1) && board[endRow][endCol] != nullptr) {
            if(board[endRow][endCol] != nullptr && board[endRow][endCol]->getSymb() == 'K') winFlag = true;
            board[endRow][endCol] = board[row][col];
            board[row][col] = nullptr;
            row = endRow;
            col = endCol;
            return true;
        }
        else {
            std::cout << "Incorrect indices for move" << std::endl;
            return false;
        } 
    }
    else if(color == 'w') {
        if(row == 6) {
            if(endRow - row <= -1 && endRow - row >= -2 && col == endCol && board[row - 1][col] == nullptr && board[row - 2][col] == nullptr) {
                if(board[endRow][endCol] != nullptr && board[endRow][endCol]->getSymb() == 'K') winFlag = true;
                board[endRow][endCol] = board[row][col];
                board[row][col] = nullptr;
                row = endRow;
                return true;
            }
        }
        if(endRow - row == -1 && col == endCol && board[endRow][endCol] == nullptr) {
            if(board[endRow][endCol] != nullptr && board[endRow][endCol]->getSymb() == 'K') winFlag = true;
            board[endRow][endCol] = board[row][col];
            board[row][col] = nullptr;
            row = endRow;
            return true;
        }
        if(endRow - row == -1 && (endCol - col == -1 || endCol - col == 1) && board[endRow][endCol] != nullptr) {
            if(board[endRow][endCol] != nullptr && board[endRow][endCol]->getSymb() == 'K') winFlag = true;
            board[endRow][endCol] = board[row][col];
            board[row][col] = nullptr;
            row = endRow;
            col = endCol;
            return true;
        }
        else {
            std::cout << "Incorrect indices for move" << std::endl;
            return false;
        } 
    }
    return false;
}

Rook::Rook(int Row, int Col, char Color) {
    row = Row;
    col = Col;
    color = Color;
    symb = 'r';
}

bool Rook::move(int endRow, int endCol, std::vector<std::vector<Piece*>>& board, char& curColor, bool& winFlag) {
    if(board[row][col]->getColor() != curColor || (board[endRow][endCol] != nullptr && board[endRow][endCol]->getColor() == curColor)) {
        std::cout << "Wrong piece color" << std::endl;
        return false;
    }
    if(row == endRow) {
        for(int i = std::min(col, endCol) + 1; i < std::max(col, endCol); i++) {
            if(board[row][i] != nullptr) { std::cout << "Incorrect indices for move" << std::endl; return false; }
        }
        if(board[endRow][endCol] != nullptr && board[endRow][endCol]->getSymb() == 'K') winFlag = true;
        board[endRow][endCol] = board[row][col];
        board[row][col] = nullptr;
        row = endRow;
        col = endCol;
        return true;
    }
    if(col == endCol) {
        for(int i = std::min(row, endRow) + 1; i < std::max(row, endRow); i++) {
            if(board[i][col] != nullptr) { std::cout << "Incorrect indices for move" << std::endl; return false; }
        }
        if(board[endRow][endCol] != nullptr && board[endRow][endCol]->getSymb() == 'K') winFlag = true;
        board[endRow][endCol] = board[row][col];
        board[row][col] = nullptr;
        row = endRow;
        col = endCol;
        return true;
    }
    else {
        std::cout << "Incorrect indices for move" << std::endl;
        return false;
    }
}

Knight::Knight(int Row, int Col, char Color) {
    row = Row;
    col = Col;
    color = Color;
    symb = 'k';
}

bool Knight::move(int endRow, int endCol, std::vector<std::vector<Piece*>>& board, char& curColor, bool& winFlag) {
    if(board[row][col]->getColor() != curColor || (board[endRow][endCol] != nullptr && board[endRow][endCol]->getColor() == curColor)) {
        std::cout << "Wrong piece color" << std::endl;
        return false;
    }
    if(abs(endRow - row) == 1 && abs(endCol - col) == 2 || abs(endCol - col) == 1 && abs(endRow - row) == 2) {
        if(board[endRow][endCol] != nullptr && board[endRow][endCol]->getSymb() == 'K') winFlag = true;
        board[endRow][endCol] = board[row][col];
        board[row][col] = nullptr;
        row = endRow;
        col = endCol;
        return true;
    }
    else {
        std::cout << "Incorrect indices for move" << std::endl;
        return false;
    }
}

Bishop::Bishop(int Row, int Col, char Color) {
    row = Row;
    col = Col;
    color = Color;
    symb = 'b';
}

bool Bishop::move(int endRow, int endCol, std::vector<std::vector<Piece*>>& board, char& curColor, bool& winFlag) {
    if(board[row][col]->getColor() != curColor || (board[endRow][endCol] != nullptr && board[endRow][endCol]->getColor() == curColor)) {
        std::cout << "Wrong piece color" << std::endl;
        return false;
    }
    if(abs(endRow - row) == abs(endCol - col) ) {
        if(board[endRow][endCol] != nullptr && board[endRow][endCol]->getSymb() == 'K') winFlag = true;
        board[endRow][endCol] = board[row][col];
        board[row][col] = nullptr;
        row = endRow;
        col = endCol;
        return true;
    }
    else {
        std::cout << "Incorrect indices for move" << std::endl;
        return false;
    }
}

King::King(int Row, int Col, char Color) {
    row = Row;
    col = Col;
    color = Color;
    symb = 'K';
}

bool King::move(int endRow, int endCol, std::vector<std::vector<Piece*>>& board, char& curColor, bool& winFlag) {
    if(board[row][col]->getColor() != curColor || (board[endRow][endCol] != nullptr && board[endRow][endCol]->getColor() == curColor)) {
        std::cout << "Wrong piece color" << std::endl;
        return false;
    }
    if(abs(endRow - row) <= 1 && abs(endCol - col) <= 1) {
        board[endRow][endCol] = board[row][col];
        board[row][col] = nullptr;
        row = endRow;
        col = endCol;
        return true;
    }
    else {
        std::cout << "Incorrect indices for move" << std::endl;
        return false;
    }
}

Queen::Queen(int Row, int Col, char Color) {
    row = Row;
    col = Col;
    color = Color;
    symb = 'q';
}

bool Queen::move(int endRow, int endCol, std::vector<std::vector<Piece*>>& board, char& curColor, bool& winFlag) {
    if(board[row][col]->getColor() != curColor || (board[endRow][endCol] != nullptr && board[endRow][endCol]->getColor() == curColor)) {
        std::cout << "Wrong piece color" << std::endl;
        return false;
    }
    if(abs(endRow - row) == abs(endCol - col) || endRow == row || endCol == col) {
        if(board[endRow][endCol] != nullptr && board[endRow][endCol]->getSymb() == 'K') winFlag = true;
        board[endRow][endCol] = board[row][col];
        board[row][col] = nullptr;
        row = endRow;
        col = endCol;
        return true;
    }
    else {
        std::cout << "Incorrect indices for move" << std::endl;
        return false;
    }
}

void Piece::printPiece() const { 
    std::cout << symb; 
}

char Piece::getColor() const {
    return color;
}

char Piece::getSymb() const {
    return symb;
}

int convert(char x) {
    switch (x) {
    case 'a':
        return 0;
        break;
    case 'b':
        return 1;
        break;
    case 'c':
        return 2;
        break;
    case 'd':
        return 3;
        break;
    case 'e':
        return 4;
        break;
    case 'f':
        return 5;
        break;
    case 'g':
        return 6;
        break;
    case 'h':
        return 7;
        break;
    default:
        break;
    }
    return 0;
}