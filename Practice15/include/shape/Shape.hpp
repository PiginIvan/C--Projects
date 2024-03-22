#ifndef SHAPE_HPP
#define SHAPE_HPP
#include <vector>

class Shape {
public:
    virtual double countPerimeter() const = 0;
    virtual void printShape() = 0;
    int getID() const;
    
protected:
    int id;
};

class Rectangle : public Shape {
private:
    int width, height;

public:
    Rectangle(int W, int H, int ID);
    double countPerimeter() const override;
    void printShape() override;

};

class Circle : public Shape {
private:
    int radius;

public:
    Circle(int R, int ID);
    double countPerimeter() const override;
    void printShape() override;

};

class Triangle : public Shape {
private:
    std::pair<int, int> side1;
    std::pair<int, int> side2;
    std::pair<int, int> side3;

public:
    Triangle(std::pair<int, int>* P1, std::pair<int, int>* P2, std::pair<int, int>* P3, int ID);
    double countPerimeter() const override;
    void printShape() override;
    void addPoint(int ind, std::pair<int, int> P);

};

void initShapes(int& curID, int numberOfFigures, std::vector<Shape*>& shapes);
void printShapes(int numberOfFigures, std::vector<Shape*>& shapes);

#endif