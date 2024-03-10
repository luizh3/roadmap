#include <iostream>

namespace MyNamespace {
    class MyClass {
    public:
        MyClass() : _value( 0 ){}
        int _value;
    };

    std::ostream& operator<<( std::ostream& ostream, const MyClass& object ) {
        ostream << "MyClass: " << object._value;
        return ostream;
    }
}

int main() {
    MyNamespace::MyClass object;
    object._value = 42;
    std::cout << object << std::endl; // ADL is used to find the correct overloaded 'operator<<'.
}
