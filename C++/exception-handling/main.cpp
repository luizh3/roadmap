#include <iostream>

// Base execptions
// std::exception: Base class for all standard exceptions.
// std::logic_error: Represents errors which can be detected statically by the program.
// std::runtime_error: Represents errors occurring during the execution of a program.

int divide( int a, int b ) {

    if( b == 0 ) {
        throw "Division by zero!";
    }

    return a / b;
}

void onDivide() {

    int num1, num2;

    std::cout << "Enter two numbers for division: ";
    std::cin >> num1 >> num2;

    try {
        int result = divide(num1, num2);
        std::cout << "The result is: " << result << std::endl;
    } catch ( const char* msg ) {
        std::cerr << "Error: " << msg << std::endl;
    }

}

int main() {

}
