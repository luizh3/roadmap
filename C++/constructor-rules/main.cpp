#include <iostream>

class RuleOfTree {

    // Constructor and destructor
    RuleOfTree() : data( new int[100] ) {}

    ~RuleOfTree() {
        delete[] data;
    }

    // Copy constructor
    RuleOfTree(const RuleOfTree& other) : data(new int[100]) {
        std::copy(other.data, other.data + 100, data);
    }

    // Copy assignment operator
    RuleOfTree& operator=(const RuleOfTree& other) {
        if (&other == this) { return *this; }
        std::copy(other.data, other.data + 100, data);
        return *this;
    }

private:
    int* data;
};

class RuleOfFive {
public:
    // Constructors and destructor
    RuleOfFive() : data(new int[100]) {}

    ~RuleOfFive() {
        delete[] data;
    }

    // Copy constructor
    RuleOfFive(const RuleOfFive& other) : data(new int[100]) {
        std::copy(other.data, other.data + 100, data);
    }

    // Copy assignment operator
    RuleOfFive& operator=(const RuleOfFive& other) {
        if (&other == this) { return *this; }
        std::copy(other.data, other.data + 100, data);
        return *this;
    }

    // Move constructor
    RuleOfFive(RuleOfFive&& other) noexcept : data(other.data) {
        other.data = nullptr;
    }

    // Move assignment operator
    RuleOfFive& operator=(RuleOfFive&& other) noexcept {
        if (&other == this) { return *this; }
        delete[] data;
        data = other.data;
        other.data = nullptr;
        return *this;
    }

private:
    int* data;
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
