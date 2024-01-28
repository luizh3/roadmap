#include <iostream>
#include <functional>

// Source https://roadmap.sh/cpp

using namespace std;

int multiplyNumbers( int first, int second );

int addNumbers( const int first, const int second )  {
    return first + second;
}

void callBack( const std::function<string( int age, const string& name)>& getStringFormated ) {
    cout << getStringFormated( 18, "Eli" ) << endl;
}

int main() {

    const int firstNumber = 10;
    const int secondNumber = 20;

    cout << "Numbers: firstNumber = " << firstNumber << ", secondNumber = " << secondNumber << endl;

    cout << "Sum value: " << addNumbers( firstNumber, secondNumber ) << endl;

    cout << "Multiply value: " << multiplyNumbers( firstNumber, secondNumber ) << endl;

    // Lambda function

    {
        auto subtraction = []( int first, int second ) -> int {
            return first - second;
        };

        cout << "Subtraction value: " << subtraction( 10, 20 ) << endl;
    }

    {
        int multiplier = 3;
        auto times = [multiplier]( int number ) -> int {
            return number * multiplier;
        };

        cout << "Multiplication value: " << times( 5 ) << endl;

    }

    {
        int expiresInDays = 45;
        auto updateDays = [&expiresInDays](int newDays) {
            expiresInDays = newDays;
        };
        updateDays(30);

        cout << "Expires in Days: " << expiresInDays << endl;
    }

    {
        std::function<int( int first, int second )> sum = []( int first, int second) -> int {
            return first + second;
        };

        cout << "Sum value: " << sum( 10, 20 ) << endl;
    }

    {
        callBack([]( int age, const string& name ) -> string {
            return "My name is " + name + " and my age is " + to_string(age);
        });
    }

    return 0;
}

int multiplyNumbers( int first, int second ) {
    return first * second;
}
