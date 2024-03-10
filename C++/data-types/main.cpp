#include <iostream>
#include <typeinfo>

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

void cast_funcionalities(){

    int x = 42;
    float y = 3.14f;
    string name = "test";

    void* my_pointer;

    my_pointer = &x;
    cout << "X value is: " << *(static_cast<int*>(my_pointer)) << endl;

    my_pointer = &y;
    cout << "Y value is: " << *(static_cast<float*>(my_pointer)) << endl;

    my_pointer = &y;
    cout << "Name is: " << *(static_cast<string*>(my_pointer)) << endl;


    // C++ 17

//    std::any any_value;
//
//    any_value = 42;
//    cout << "int value: " << any_cast<int>(any_value) << endl;
//
//    any_value = 3.14;
//    cout << "double value: " << any_cast<double>(any_value) << endl;
//
//    any_value = string("Hello, world!");
//    cout << "string value: " <<  any_cast<string>(any_value) << endl;

}

class Base { virtual void dummy() {} };
class Derived : public Base { /* ... */ };

void rtti() { // Run-Time Type Identification

    Base* base_ptr = new Derived;

    // Using typeid to get the type of the object
    std::cout << "Type: " << typeid(*base_ptr).name() << '\n';

    delete base_ptr;

}

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

    rtti();

    return 0;
}
