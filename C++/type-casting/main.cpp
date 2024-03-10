#include <iostream>
#include <memory>

class Base {
public:
    virtual void init() const {
        std::cout << "Base::init" << std::endl;
    }
};
class Derived : public Base {
public:
    void init() const override {
        std::cout << "Derived::init" << std::endl;
    }
};

int main() {

    {
        const int number = 10;
        const float floatNumber = (float)number;
        std::cout << "Float number: " << floatNumber << std::endl;
    }

    {
        const int number = 10;
        const float floatNumber = static_cast<float>( number );
        std::cout << "Float number: " << floatNumber << std::endl;
    }

    {
        std::unique_ptr<Base> base( new Derived() );
        const Derived* derived = dynamic_cast<Derived*>( base.get() );
        derived->init();
    }

    {
        std::unique_ptr<Base> base( new Base() );
        const Derived* derived = dynamic_cast<Derived*>( base.get() );
        std::cout << "Is Derived: " << ( derived != nullptr ) << std::endl;
    }

    {
        int* value = new int( 42 );
        const long long longLongValue = reinterpret_cast<long long>( value );
        std::cout << "Long long value:" << longLongValue << std::endl;
    }

    {
        const int value = 10;
        int* ptr = const_cast<int*>(&value);
        *ptr = 25;
        std::cout << "Const cast value: " << *ptr << std::endl;
    }

    return 0;
}
