#include <iostream>

#define PI 3.14

#define SQUARE(x)( (x) * (x) )

#define DEBUG_MODE

double circumference( const int radius ) {
    return 2 * PI * radius;
}


int main() {

    std::cout << "Circumference radius 10: " << circumference( 10 ) << std::endl;

    std::cout << "Square of 10: " << SQUARE( 10 ) << std::endl;

#ifdef DEBUG_MODE
    std::cout << "Debug mode enabled";
#else
    std::cout << "Debug mode disabled";
#endif

    return 0;
}
