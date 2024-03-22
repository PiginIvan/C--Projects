#ifndef PIECE_HPP
#define PIECE_HPP
#include <vector>

class Piece {
protected:
    int row, col;
    char symb, color;
    
public:
    void printPiece() const;
    virtual bool move(int endRow, int endCol, std::vector<std::vector<Piece*>>& board, char& curColor, bool& winFlag) = 0;
    char getColor() const;
    char getSymb() const;
    Piece& operator=(const Piece& other);
};

class Pawn : public Piece {
public:
    Pawn(int Row, int Col, char Color);
    bool move(int endRow, int endCol, std::vector<std::vector<Piece*>>& board, char& curColor, bool& winFlag) override;
};

class Rook : public Piece {
public:
    Rook(int Row, int Col, char Color);
    bool move(int endRow, int endCol, std::vector<std::vector<Piece*>>& board, char& curColor, bool& winFlag) override;
};

class Knight : public Piece {
public:
    Knight(int Row, int Col, char Color);
    bool move(int endRow, int endCol, std::vector<std::vector<Piece*>>& board, char& curColor, bool& winFlag) override;
};

class Bishop : public Piece {
public:
    Bishop(int Row, int Col, char Color);
    bool move(int endRow, int endCol, std::vector<std::vector<Piece*>>& board, char& curColor, bool& winFlag) override;
};

class King : public Piece {
public:
    King(int Row, int Col, char Color);
    bool move(int endRow, int endCol, std::vector<std::vector<Piece*>>& board, char& curColor, bool& winFlag) override;
};

class Queen : public Piece {
public:
    Queen(int Row, int Col, char Color);
    bool move(int endRow, int endCol, std::vector<std::vector<Piece*>>& board, char& curColor, bool& winFlag) override;
};

void initBoard(std::vector<std::vector<Piece*>>& board);
void printBoard(const std::vector<std::vector<Piece*>> board);
int convert(char x);

#endif