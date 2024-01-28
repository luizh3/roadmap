#include <iostream>

// Source https://roadmap.sh/cpp

using namespace std;

struct Person {
    string name;
    int age;
    float height;
};

class Animal {
public:
    Animal( string dsName, int nrAge ) :
    _dsName( dsName ), _nrAge( nrAge ) {}

    void printInformations() const {
        cout << "Name: " << _dsName << ", Age: " << _nrAge << endl;
    }
private:
    string _dsName;
    int _nrAge;
};

union Data {
    int number;
    char letter;
    float decimal;
};

int main() {


    int num = 42; // The size of int depends on the system architecture (usually 4 bytes).

    /*
    short (short int): Smaller range than int.
    long (long int): Larger range than int.
    long long (long long int): Even larger range than long int.
    */

    float pi = 3.14f; // Provides single-precision floating-point numbers. It typically occupies 4 bytes of memory.

    double pi_high_precision = 3.1415926535; // Provides double-precision floating-point numbers. It consumes more memory (usually 8 bytes) but has a higher precision than float.

    char letter = 'A'; // Characters represent a single character, such as a letter, digit, or symbol. They are stored using the ASCII value of the symbol and typically occupy 1 byte of memory.

    bool is_cpp_great = true; // Booleans represent logical values: true or false. They usually occupy 1 byte of memory.

    // Arrays

    int numbers[5] = {1, 2, 3, 4, 5}; // Arrays are used to store multiple values of the same data type in consecutive memory locations.

    // Pointers

    int age = 32;
    int* pointerAge = &age;

    // References

    int& ageReference = age;

    Person person = {"Test", 30, 5.19 };

    Animal animal( "Cat", 5 );

    animal.printInformations();

    // Unions

    // Unions are used to store different data types in the same memory location.

    Data myData;
    myData.number = 42;

    cout << "Union number: " << myData.number << endl;

    myData.letter = 'A';

    cout << "Union letter: " << myData.letter << endl;

    cout << "Union number now is not set: " << myData.number << endl;

    return 0;
}
