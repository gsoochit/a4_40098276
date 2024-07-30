#ifndef RHOMBUS_H
#define RHOMBUS_H

#include "Shape.h"

class Rhombus : public Shape {
private:
    int diagonal;

public:
    Rhombus(std::string name = "Diamond", char pen = '*', int identity = 0, int diagonal = 1);
    // Constructor
    Rhombus(int d, char pen, std::string name);

    // Override pure virtual functions from Shape
    int get_height() const override;
    int get_width() const override;

    // Accessor (Getter) Functions
    int getDiagonal() const;

    // Mutator (Setter) Functions
    void setDiagonal(int diagonal);

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

    void printSampleTextualImage() const ;

      // toString method
    std::string toString() const override;


// Overloaded Output Operator for Rhombus
friend std::ostream& operator<<(std::ostream& os, const Rhombus& rhombus) ;

};

#endif // RHOMBUS_H