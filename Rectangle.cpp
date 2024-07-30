#include "Rectangle.h"
#include <iostream>
#include <iomanip>
#include <sstream>

Rectangle::Rectangle(std::string name, char pen, int identity, int height, int width)
    : Shape(name, pen, identity), height(height), width(width) {
    if (height < 1) {
        height = 1;
    }
    if (width < 1) {
        width = 1;
    }
}

int Rectangle::get_height() const {
    return height;
}

int Rectangle::get_width() const {
    return width;
}

void Rectangle::setHeight(int height) {
    this->height = height;
    if (height < 1) {
        height = 1;
    }
}

void Rectangle::setWidth(int width) {
    this->width = width;
    if (width < 1) {
        width = 1;
    }
}

double Rectangle::areaGeo() const {
    return height * width;
}

double Rectangle::perimeterGeo() const {
    return 2 * (height + width);
}

int Rectangle::areaTxt() const {
    return height * width;
}

int Rectangle::perimeterTxt() const {
    if (height > 1 && width > 1) {
        return 2 * (height + width) - 4;
    } else {
        return height * width;
    }
}

Canvas Rectangle::draw() const {
    Canvas can(get_height(), get_width());
    for (int r = 0; r < get_height(); ++r) {
        for (int c = 0; c < get_width(); ++c) {
            can.put(r, c, getPen());
        }
    }
    return can;
}

// Sample textual image
void Rectangle::printSampleTextualImage() const {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            std::cout << getPen();
        }
        std::cout << std::endl;
    }
}

// toString implementation
std::string Rectangle::toString() const {
    std::ostringstream oss;
    oss << "Shape Information\n";
    oss << "-----------------\n";
    oss << "id: " << getidentity() << "\n"; // Ensure Shape class provides getIdentity()
    oss << "Shape name: " << getName() << "\n";
    oss << "Pen character: " << getPen() << "\n";
    oss << "Height: " << height << "\n";
    oss << "Width: " << width << "\n";
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
std::ostream& operator<<(std::ostream& os, const Rectangle& rect) {
    os << rect.toString();
    return os;
}
