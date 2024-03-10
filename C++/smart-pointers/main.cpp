#include <iostream>

#include <memory>

struct MyDeleterUniquePointer {
    void operator()( int* ptr ) {
        std::cout << "MyDeleterUniquePointer::operator deleting pointer" << std::endl;
        delete ptr;
    }
};

void example_unique_ptr() {

    {
        std::unique_ptr<int> p1( new int(5) );
        std::unique_ptr<int> p2 = std::make_unique<int>(10);

        std::cout << "example_unique_ptr p1:" << *p1 << ", p2:" << *p2 << std::endl;
    }

    {

        std::unique_ptr<int> p1( new int(10) );
        std::unique_ptr<int> p2 = std::move( p1 );

        if( p1 ) {
            std::cout << "example_unique_ptr P1 owns the object, VALUE:" << *p1 << std::endl;
        } else if ( p2 ) {
            std::cout << "example_unique_ptr P2 owns the objetc, VALUE:" << *p2 << std::endl;
        }

    }

    {
        std::unique_ptr<int, MyDeleterUniquePointer> p1( new int( 5 ), MyDeleterUniquePointer() );
    }

};

class MyClass {
public:
    void doSomething() {
        std::cout << "MyClass::Doing something" << std::endl;
    }

    MyClass() {
        std::cout << "MyClass::Constructor is called." << std::endl;
    }
    ~MyClass() {
        std::cout << "MyClass::Destructor is called." << std::endl;
    };
};

void example_shared_ptr() {

    std::shared_ptr<MyClass> ptr1( new MyClass() );

    {
        std::shared_ptr<MyClass> ptr2 = ptr1;

        std::cout << "example_shared_ptr Inside the inner scope." << std::endl;
    }

    std::cout << "example_shared_ptr Outside the inner scope." << std::endl;

}

void example_weak_ptr() {

    std::weak_ptr<MyClass> weak_ptr;

    {
        std::shared_ptr<MyClass> shared_ptr = std::make_shared<MyClass>();
        weak_ptr = shared_ptr;

        if( auto sharedFromWeak = weak_ptr.lock() ){
            sharedFromWeak->doSomething();
            std::cout << "example_weak_ptr Shared uses count: " << sharedFromWeak.use_count() << std::endl;
        }

    }

    if( auto sharedFromWeak = weak_ptr.lock() ) {
        // This block will not be executed because the object is destroyed
    }
    else {
        std::cout << "Object has been destroyed" << std::endl;
    }

}

int main() {

    example_unique_ptr();
    example_shared_ptr();
    example_weak_ptr();

    return 0;
}
