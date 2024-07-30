#include "AcuteTriangle.h"
#include <cmath>
#include <sstream>
#include <iomanip>

AcuteTriangle::AcuteTriangle(std::string name, char pen, int identity, int base)
    : Shape(name, pen, identity), base(base) {
    if (base % 2 == 0) {
        base++;
    }
    if (base < 1) {
        base = 1;
    }
}

AcuteTriangle::AcuteTriangle(int base)
    : Shape(), base(base) {
    if (base % 2 == 0) {
        base++;
    }
    if (base < 1) {
        base = 1;
    }
}

int AcuteTriangle::getBase() const {
    return base;
}

void AcuteTriangle::setBase(int base) {
    this->base = base;
    if (base % 2 == 0) {
        base++;
    }
    if (base < 1) {
        base = 1;
    }
}

int AcuteTriangle::get_height() const {
    return (base + 1) / 2;
}

int AcuteTriangle::get_width() const {
    return base;
}

double AcuteTriangle::areaGeo() const {
    return (base + 1) / 2.0 * base / 2.0;
}

double AcuteTriangle::perimeterGeo() const {
    return base + sqrt(base * base + 4 * ((base + 1) / 2) * ((base + 1) / 2));
}

int AcuteTriangle::areaTxt() const {
    return ((base + 1) / 2) * ((base + 1) / 2);
}

int AcuteTriangle::perimeterTxt() const {
    if (base > 1) {
        return 4 * (((base + 1) / 2) - 1);
    } else {
        return 1;
    }
}

Canvas AcuteTriangle::draw() const {
    Canvas can(get_height(), get_width());
    for (int i = 0; i < get_height(); ++i) {
        int start_col = get_height() - 1 - i;
        int end_col = get_height() - 1 + i;
        for (int j = start_col; j <= end_col; ++j) {
            can.put(i, j, getPen());
        }
    }
    return can;
}

// void AcuteTriangle::printSampleTextualImage() const {
//     for (int i = 0; i < (base + 1) / 2; i++) {
//         for (int j = 0; j <= i; j++) {
//             std::cout << getPen();
//         }
//         std::cout << std::endl;
//     }
// }

std::string AcuteTriangle::toString() const {
    std::ostringstream oss;
    oss << "Shape Information\n";
    oss << "-----------------\n";
    oss << "id: " << getidentity() << "\n";
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

std::ostream& operator<<(std::ostream& os, const AcuteTriangle& at) {
    os << at.toString();
    return os;
}
