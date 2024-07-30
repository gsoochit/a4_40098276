#include <iostream>
#include "Canvas.h"
#include <clocale>
#include "Rectangle.h"
#include "Shape.h" // Include Shape.h if it's not already included
#include "Rhombus.h"
#include "AcuteTriangle.h"
#include "RightTriangle.h"

using std::cout;
using std::endl;

int main() {
    // std::cout << std::setlocale(LC_ALL, "en_US.UTF-8") << std::endl;
    // Canvas can1{6, 8};
    // cout << "(a)\n" << can1 << "\n";

    // can1.write_horizontal(2, 3, "∗");
    // cout << "(b)\n" << can1 << "\n";
    // can1.write_horizontal(3, 3, "∗∗");
    // cout << "(c)\n" << can1 << "\n";
    // can1.write_horizontal(4, 3, "∗∗∗");
    // cout << "(d)\n" << can1 << "\n";
    // can1.write_horizontal(5, 3, "****");
    // cout << "(e)\n" << can1 << "\n";
    // Canvas can2{ 3, 10 };
    // can2.write_horizontal(2, 2, "bonjour");
    // cout << "(f)\n" << can2 << "\n";
    // Canvas can3{ can1.concat(can2) };
    // cout << "(g)\n" << can3 << "\n";

//     // Create a Rectangle object
    Rectangle rect{ 5, 7 };
//     // Print the Rectangle object
   cout << rect.toString() << endl;


//   // Create a Rectangle object
//     Rectangle rect1{ 10, 12 };
//     // Print the Rectangle object
//    cout << rect1.toString() << endl;


//Rhombus 
   Rhombus ace{16, 'v', "Ace of diamond"};
// cout << ace.toString() << endl;
// or, equivalently:
cout << ace << endl;





AcuteTriangle at{ 17 };
cout << at << endl;

// // equivalently:

// Shape *atPtr = &at;
// cout << *atPtr << endl;

// Shape &atRef = at;
// cout << atRef << endl;


RightTriangle rt{ 10, 'L', "Carpenter’ s square" };
cout << rt << endl;
// or equivalently
// cout << rt.toString() << endl;


Canvas rectCan{ rect.draw() };
cout << rectCan << endl;



Canvas aceCan{ ace.draw() }; // or, Canvas aceCan = ace.draw();
cout << aceCan << endl;

at.setPen('^');
Canvas atCan{ at.draw() };
cout << atCan << endl;


Canvas rtCan{ rt.draw() };
cout << rtCan << endl;


rt.setPen('0');
Canvas rtQuadrant_1{ rt.draw() };
cout << rtQuadrant_1 << endl;

Canvas rtQuadrant_2{ rtQuadrant_1.flip_horizontal() };
cout << rtQuadrant_2 << endl;

Canvas rtQuadrant_3{ rtQuadrant_2.flip_vertical() };
cout << rtQuadrant_3 << endl;

Canvas rtQuadrant_4{ rtQuadrant_3.flip_horizontal() };
cout << rtQuadrant_4 << endl;

    return 0;
}

