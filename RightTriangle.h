#ifndef RIGHTTRIANGLE_H
#define RIGHTTRIANGLE_H

#include "Shape.h"

class RightTriangle : public Shape {
private:
    int base;

public:
    RightTriangle(std::string name = "Ladder", char pen = '*', int identity = 0, int base = 1);
RightTriangle(int base, char pen, const std::string& name);

    // Accessor (Getter) Functions
    int getBase() const;

    // Mutator (Setter) Functions
    void setBase(int base);

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

    void printSampleTextualImage() const;
      // toString method
    std::string toString() const override;

    // Implement abstract methods from Shape
    int get_height() const override;  // Implement get_height
    int get_width() const override;   // Implement get_width
};

#endif // RIGHTTRIANGLE_H