#include "Shape.h"
#include <iostream>
#include <sstream>
#include <iomanip>



// Shape::Shape(std::string name, char pen, int identity)
//     : name(name), pen(pen), identity(identity) {}

int Shape::nextId = 1; // Initialize the static member variable

Shape::Shape(std::string name, char pen, int identity)
    : name(name), pen(pen), identity(identity) {
    if (identity == 0) { // Default ID is 0, assign a new unique ID
        identity = nextId++;
    }
}

std::string Shape::getName() const {
    return name;
}

char Shape::getPen() const {
    return pen;
}

int Shape::getidentity() const {
    return identity;
}

void Shape::setName(const std::string& name) {
    this->name = name;
}

void Shape::setPen(char pen) {
    this->pen = pen;
}


std::ostream& operator<<(std::ostream& os, const Shape& shape) {
    os << shape.toString();
    return os;
}

std::string Shape::toString() const{
 std::ostringstream oss;
    oss << "Shape Information\n";
    oss << "-----------------\n";
    oss << "id: " << getidentity() << "\n"; // Ensure Shape class provides getIdentity()
    oss << "Shape name: " << getName() << "\n";
    oss << "Pen character: " << getPen() << "\n";
    oss << "Height: " << get_height() << "\n";
    oss << "Width: " << get_width() << "\n";
    oss << "Textual area: " << areaTxt() << "\n";
    oss << std::fixed << std::setprecision(2);
    oss << "Geometric area: " << areaGeo() << "\n";
    oss << "Textual perimeter: " << perimeterTxt() << "\n";
    oss << "Geometric perimeter: " << perimeterGeo() << "\n";
    oss << "Static type: " << typeid(this).name() << "\n";
    oss << "Dynamic type: " << typeid(*this).name() << "\n";
    return oss.str();
}