#include "triangle.h"

Triangle::Triangle(std::string name, char pen, int identity, int base, int height)
    : Shape(name, pen, identity), base(base), height(height) {}

int Triangle::getBase() const {
    return base;
}

int Triangle::getHeight() const {
    return height;
}

void Triangle::setBase(int base) {
    this->base = base;
}

void Triangle::setHeight(int height) {
    this->height = height;
}

double Triangle::areaGeo() const {
    return 0.5 * base * height;
}

double Triangle::perimeterGeo() const {
    // Calculate perimeter based on base and height
    return 0.0; // TO DO: implement perimeter calculation
}

