#define _USE_MATH_DEFINES
#include "Shape.hpp"
#include <cmath>
#include <iostream>

int Shape::getID() const { return id; }

Rectangle::Rectangle(int W, int H, int ID) : width(W), height(H) { id = ID; }

double Rectangle::countPerimeter() const {
    return 2 * (width + height);
}

void Rectangle::printShape() {
    std::cout << "Rectangle: id: " << id << " width: " << width << " height: " << height << std::endl;
}

Circle::Circle(int R, int ID) : radius(R) { id = ID; }

double Circle::countPerimeter() const {
    return 2 * radius * M_PI;
}

void Circle::printShape() {
    std::cout << "Circle: id: " << id << " radius: " << radius << std::endl;
}

Triangle::Triangle(std::pair<int, int>* P1, std::pair<int, int>* P2, std::pair<int, int>* P3, int ID) : 
    side1(*P1), side2(*P2), side3(*P3) { id = ID; }

double Triangle::countPerimeter() const {
    int len1 = sqrt(pow((side1.first - side2.first), 2) + pow((side1.second - side2.second), 2));
    int len2 = sqrt(pow((side1.first - side3.first), 2) + pow((side1.second - side3.second), 2));
    int len3 = sqrt(pow((side2.first - side3.first), 2) + pow((side2.second - side3.second), 2));
    return (len1 + len2 + len3);
}

void Triangle::addPoint(int ind, std::pair<int, int> P) {
    if(ind == 0) { side1 = P; return; }
    else if(ind == 1) { side2 = P; return; }
    side3 = P;
}

void Triangle::printShape() {
    std::cout << "Triangle: id: " << id << " Points: " << "(" << side1.first << " " << side1.second << ") " 
        << "(" << side2.first << " " << side2.second << ") " << "(" << side3.first << " " << side3.second << ") " << std::endl;
    
}

void initShapes(int& curID, int numberOfFigures, std::vector<Shape*>& shapes) {
    for(int i = 0; i < numberOfFigures; i++) {
        std::cout << "Choose type of figure(1 - rectangle, 2 - circle, 3 - triangle): ";
        int figType;
        std::cin >> figType;
        switch(figType) {
            case(1):
                std::cout << "Enter width and height: ";
                int W, H;
                std::cin >> W >> H;
                shapes.push_back(new Rectangle(W, H, curID++));
                break;  

            case(2):
                std::cout << "Enter radius: ";
                int R;
                std::cin >> R;
                shapes.push_back(new Circle(R, curID++));
                break;

            case(3):
                std::cout << "Enter 6 coordinates of 3 points: ";
                int p1, p2, p3, p4, p5, p6;
                std::cin >> p1 >> p2 >> p3 >> p4 >> p5 >> p6;
                shapes.push_back(new Triangle(new std::pair<int, int>(p1, p2), new std::pair<int, int>(p3, p4), new std::pair<int, int>(p5, p6), curID++));     
                break;
        }

    }
}

void printShapes(int numberOfFigures, std::vector<Shape*>& shapes) {
    for(int i = 0; i < numberOfFigures; i++) {
        shapes[i]->printShape();
        std::cout << "Perimeter: " << shapes[i]->countPerimeter() << std::endl;
    }
}