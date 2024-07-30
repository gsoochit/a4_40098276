#ifndef SHAPE_H
#define SHAPE_H

#include <string>
#include <iostream>
#include <memory>
#include "Canvas.h"
#include <typeinfo> // For typeid

class Shape {
private:
    std::string name;
    char pen;
    int identity;
    static int nextId; 
    
public:
    // Constructor
    Shape(std::string name = "", char pen = '*', int identity = 0);


    // Accessor (Getter) Functions
    std::string getName() const;
    char getPen() const;
    int getidentity() const;

    // Mutator (Setter) Functions
    void setName(const std::string& name);
    void setPen(char pen);

    // toString
    // std::string toString() const;

    // Geometric Calculations
    virtual double areaGeo() const = 0;
    virtual double perimeterGeo() const = 0;

    // Textual Calculations
    virtual int areaTxt() const = 0;
    virtual int perimeterTxt() const = 0;

    // Drawing on Canvas
    virtual Canvas draw() const = 0; // Pure virtual function

    // Height and Width Calculations
    virtual int get_height() const = 0;
    virtual int get_width() const = 0;

    // Overloaded Polymorphic Output Operator
    friend std::ostream& operator<<(std::ostream& os, const Shape& shape);
     virtual std::string toString() const = 0;
};

#endif // SHAPE_H
