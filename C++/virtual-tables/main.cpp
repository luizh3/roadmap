#include <iostream>

class Base {
public:
    virtual void function1() {
        std::cout << "Base::function1" << std::endl;
    }

    virtual void function2() {
        std::cout << "Base::function2" << std::endl;
    }
};

class Derived : public Base {
public:
    void function1() override {
        std::cout << "Derived::function1" << std::endl;
    }
    void function3() { //  Is not part of the Vtable, as it is not a virtual function.
        std::cout << "Derived::function3" << std::endl;
    }
};

int main() {

    Base* derived = new Derived();
    derived->function1(); // The function pointer in the Vtable is used to call the correct function (in this case, Derived::function1)
    derived->function2();

    delete derived;

    return 0;
}
