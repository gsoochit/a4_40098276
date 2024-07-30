#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"
#include <string>
#include <typeinfo> // For typeid
#include <sstream>  // For std::ostringstream

class Rectangle : public Shape {
private:
    int height;
    int width;

public:
    Rectangle(std::string name = "Door", char pen = '*', int identity = 0, int height = 1, int width = 1);
    Rectangle(int height, int width) : height(height), width(width) {}

    // Accessor (Getter) Functions
    int get_height() const override;
    int get_width() const override;

    // Mutator (Setter) Functions
    void setHeight(int height);
    void setWidth(int width);

    // Geometric Area Calculation
    double areaGeo() const override;

    // Geometric Perimeter Calculation
    double perimeterGeo() const override;

    // Textual Area Calculation
    int areaTxt() const override;

    // Textual Perimeter Calculation
    int perimeterTxt() const override;

    // Drawing on Canvas
    virtual Canvas draw() const override;

    // Sample Textual Image
    void printSampleTextualImage() const;

    // String representation of the object
    std::string toString() const override;

    // Overloaded Output Operator
    friend std::ostream& operator<<(std::ostream& os, const Rectangle& rect);
};

#endif // RECTANGLE_H
