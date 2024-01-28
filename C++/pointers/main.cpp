#include <iostream>

// Source https://roadmap.sh/cpp

using namespace std;

int sum( const int firstNumber, const int secondNumber ) {
    return firstNumber + secondNumber;
}

int main() {

    int number = 10;
    int* pointer = &number;

    int valueOfPointer = *pointer;

    cout << "Value of number: " << valueOfPointer << endl;

    int(*mySumFunction)(const int, const int ) = sum;

    cout << "Sum value: " << mySumFunction( 10, 15 ) << endl;

    int& referenceNumber = number; // Reference 'ref' is now an alias of 'num'

    // Modifying the value of ref will also modify the value of num because they share the same memory location.

    return 0;
}
