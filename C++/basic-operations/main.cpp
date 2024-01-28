#include <iostream>

using namespace std;

int main() {

    const int firstNumber = 30;
    const int secondNumber = 20;

    const int sum = firstNumber + secondNumber;

    cout << "Sum value: " << sum << endl;

    const int diff = firstNumber - secondNumber;

    cout << "Diff value: " << diff << endl;

    const int product = firstNumber * secondNumber;

    cout << "Product value: " << product << endl;

    const int quotient = firstNumber / secondNumber;

    cout << "Quotient value: " << quotient << endl;

    const int remainder = firstNumber % secondNumber;

    cout << "Remainder value: " << remainder << endl;

    // Relational operators

    cout << "First number is equals that 10 ? " << ( firstNumber == 10 ) << endl;

    cout << "First number is diferrent that 10 ? " << ( firstNumber != 10 ) << endl;

    cout << "First number is greater than 10 ? " << ( firstNumber > 10 ) << endl;

    cout << "First number is less than 10 ? " << ( firstNumber < 10 ) << endl;

    cout << "First number is greater than or equal to 10 ? " << ( firstNumber >= 10 ) << endl;

    cout << "First number is less than or equal to 10 ? " << ( firstNumber <= 10 ) << endl;

    // Logical operators

    cout << "First number is equals that 10 and second number is equal that 20 ? " << ( firstNumber == 10 && secondNumber == 20 ) << endl;

    cout << "First number is equals that 10 or second number is equal that 20 ? " << ( firstNumber == 10 || secondNumber == 20 ) << endl;

    cout << "First number not is equals that 10 or second number not is equal that 20 ? " << ( !(firstNumber == 10 ) || !(secondNumber == 20) ) << endl;

    if( firstNumber == secondNumber ) {
        cout << "FirstNumber and second number is equals" << endl;
    } else {
        cout << "FirstNumber and second number are diferrent" << endl;
    }

    if ( secondNumber > 20 ) {
        cout << "SecondNumber is greater than 20" << endl;
    } else if ( secondNumber > 10 && secondNumber < 25 ) {
        cout << "SecondNumber is greater than 10 but less than 25" << endl;
    }

    // Loops

    const int myArray[5] = {10,15,20,25,30};

    for( int index = 0; index < 5; index++ ) {
        cout << "Number by Index: [INDEX] " << index << " [NUMBER] " << myArray[index] << endl;
    }

    // Foreach
    for( const int& number : myArray ) {
        cout << "Number: " << number << endl;
    }

    {
        int index = 0;
        while ( index < 5) {
            cout << "Iteration: " << index << endl;
            index++;
        }

    }

    {
        int index = 0;
        do {
            cout << "Iteration: " << index << endl;
            index++;
        } while (index < 5);
    }

    return 0;
}
