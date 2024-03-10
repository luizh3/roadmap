#include <iostream>
#include <vector>

using namespace std;

// Base case for recursion
template <typename T>
T sum(T t) {
  cout << "Primary:" << t << endl;
  return t;
}

// Variadic template
template <typename T, typename... Args>
T sum(T t, Args... args) {
    cout << "Second:" << t << endl;
    return t + sum(args...);
}

int main() {
  int result = sum(1, 2, 3, 4, 5);  // expands to 1 + 2 + 3 + 4 + 5
  cout << "The sum is: " << result << endl;

  return 0;
}