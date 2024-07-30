#include "RightTriangle.h"
#include <sstream>
#include <iomanip>
#include <cmath>
#include <iostream>

RightTriangle::RightTriangle(std::string name, char pen, int identity, int base)
    : Shape(name, pen, identity), base(base) {
    if (base < 1) {
        base = 1;
    }
}

RightTriangle::RightTriangle(int base, char pen, const std::string& name)
    : RightTriangle(name, pen, 0, base) {}

    
// Implement abstract methods from Shape
int RightTriangle::get_height() const {
    return base;  // Return height equal to base for right triangle
}

int RightTriangle::get_width() const {
    return base;  // Return width equal to base for right triangle
}

int RightTriangle::getBase() const {
    return base;
}

void RightTriangle::setBase(int base) {
    this->base = base;
    if (base < 1) {
        base = 1;
    }
}

double RightTriangle::areaGeo() const {
    return base * base / 2.0;
}

double RightTriangle::perimeterGeo() const {
    return (2 + sqrt(2)) * base;
}

int RightTriangle::areaTxt() const {
    return base * (base + 1) / 2;
}

int RightTriangle::perimeterTxt() const {
    return 3 * (base - 1);
}

Canvas RightTriangle::draw() const {
    Canvas can(get_height(), get_width());
    for (int i = 0; i < base; ++i) {
        for (int j = 0; j <= i; ++j) {
            can.put(i, j, getPen());
        }
    }
    return can;
}

// Sample textual image
void RightTriangle::printSampleTextualImage() const {
    for (int i = 0; i < base; i++) {
        for (int j = 0; j <= i; j++) {
            std::cout << getPen();
        }
        std::cout << std::endl;
    }
}

std::string RightTriangle::toString() const {
    std::ostringstream oss;
    oss << "Shape Information\n";
    oss << "-----------------\n";
    oss << "id: " << getidentity() << "\n";
    oss << "Shape name: " << getName() << "\n";
    oss << "Pen character: " << getPen() << "\n";
    oss << "Height: " << getBase() << "\n";
    oss << "Width: " << getBase() << "\n";
    oss << "Textual area: " << areaTxt() << "\n";
    oss << std::fixed << std::setprecision(2);
    oss << "Geometric area: " << areaGeo() << "\n";
    oss << "Textual perimeter: " << perimeterTxt() << "\n";
    oss << "Geometric perimeter: " << perimeterGeo() << "\n";
    oss << "Static type: " << typeid(this).name() << "\n";
    oss << "Dynamic type: " << typeid(*this).name() << "\n";
    return oss.str();
}

// Overloaded Output Operator
std::ostream& operator<<(std::ostream& os, const RightTriangle& rt) {
    os << rt.toString();
    return os;
}
