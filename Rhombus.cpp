#include "Rhombus.h"
#include <iostream>
#include <iomanip>
#include <cmath>
#include <typeinfo> // Added include for typeid
#include <sstream>

// Constructor definition
Rhombus::Rhombus(int diagonal, char pen, std::string name)
    : Shape(name, pen) {
    // Ensure diagonal is odd; if not, increment by 1
    if (diagonal % 2 == 0) {
        diagonal++;  // Ensure diagonal is odd
    }
    if (diagonal < 1) {
        diagonal = 1;  // Ensure diagonal is at least 1
    }
    this->diagonal = diagonal;
}

// Constructor definition with identity
Rhombus::Rhombus(std::string name, char pen, int identity, int diagonal)
    : Shape(name, pen, identity) {
    // Ensure diagonal is odd; if not, increment by 1
    if (diagonal % 2 == 0) {
        diagonal++;  // Ensure diagonal is odd
    }
    if (diagonal < 1) {
        diagonal = 1;  // Ensure diagonal is at least 1
    }
    this->diagonal = diagonal;
}

int Rhombus::get_height() const {
    return diagonal;
}

int Rhombus::get_width() const {
    return diagonal;
}

int Rhombus::getDiagonal() const {
    return diagonal;
}

void Rhombus::setDiagonal(int diagonal) {
    if (diagonal % 2 == 0) {
        diagonal++;  // Ensure diagonal is odd
    }
    if (diagonal < 1) {
        diagonal = 1;  // Ensure diagonal is at least 1
    }
    this->diagonal = diagonal;
}

double Rhombus::areaGeo() const {
    return diagonal * diagonal / 2.0;
}

double Rhombus::perimeterGeo() const {
    return 2 * sqrt(2) * diagonal;
}

int Rhombus::areaTxt() const {
    int n = diagonal / 2;
    return 2 * n * (n + 1) + 1;
}

int Rhombus::perimeterTxt() const {
    if (diagonal > 1) {
        return 2 * (diagonal - 1);
    } else {
        return 1;
    }
}

// Drawing on Canvas
Canvas Rhombus::draw() const {
    Canvas can(get_height(), get_width());
    int n = diagonal / 2;
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j < diagonal; ++j) {
            if (std::abs(j - n) <= i) {
                can.put(i, j, getPen());
                can.put(diagonal - 1 - i, j, getPen());
            }
        }
    }
    return can;
}

// Sample textual image
void Rhombus::printSampleTextualImage() const {
    for (int i = 0; i < diagonal; i++) {
        for (int j = 0; j < diagonal; j++) {
            if (i == j || i == diagonal - j - 1) {
                std::cout << getPen();
            } else {
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }
}

std::string Rhombus::toString() const {
    std::ostringstream oss;
    oss << "Shape Information\n";
    oss << "-----------------\n";
    oss << "id: " << getidentity() << "\n";
    oss << "Shape name: " << getName() << "\n";
    oss << "Pen character: " << getPen() << "\n";
    oss << "Diagonal length: " << diagonal << "\n";
    oss << "Textual area: " << areaTxt() << "\n";
    oss << std::fixed << std::setprecision(2);
    oss << "Geometric area: " << areaGeo() << "\n";
    oss << "Textual perimeter: " << perimeterTxt() << "\n";
    oss << "Geometric perimeter: " << perimeterGeo() << "\n";
    oss << "Static type: " << typeid(this).name() << "\n";
    oss << "Dynamic type: " << typeid(*this).name() << "\n";
    return oss.str();
}
// Overloaded Output Operator for Rhombus
std::ostream& operator<<(std::ostream& os, const Rhombus& rhombus) {
    os << rhombus.toString();
    return os;
}