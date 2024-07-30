#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "shape.h"

class Triangle : public Shape {
protected:
    int base;
    int height;

public:
    Triangle(std::string name = "", char pen = '*', int identity = 0, int base = 0, int height = 0);

    // Accessor (Getter) Functions
    int getBase() const;
    int getHeight() const;

    // Mutator (Setter) Functions
    void setBase(int base);
    void setHeight(int height);

    // Geometric Area Calculation
    double areaGeo() const override;

    // Geometric Perimeter Calculation
    double perimeterGeo() const override;

    // virtual Canvas draw() const override;
};

#endif // TRIANGLE_H