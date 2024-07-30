#ifndef ACUTETRIANGLE_H
#define ACUTETRIANGLE_H

#include "Shape.h"

class AcuteTriangle : public Shape {
private:
    int base;

public:
    AcuteTriangle(std::string name = "Wedge", char pen = '*', int identity = 0, int base = 1);
    
     // Constructor with only base argument
    AcuteTriangle(int base);


    // Override pure virtual functions from Shape
    int get_height() const override;
    int get_width() const override;

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

    // String representation
    std::string toString() const override;

    // Overloaded Output Operator
    friend std::ostream& operator<<(std::ostream& os, const AcuteTriangle& at);
};

#endif // ACUTETRIANGLE_H