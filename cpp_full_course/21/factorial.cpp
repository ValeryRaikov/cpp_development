#include <iostream>

using namespace std;

int factorial(int num);

int main() {
    int result = factorial(5);
    cout << "Factorial of 5 is " << result << '\n';

    return 0;
}

int factorial(int num) {
    if (num == 0) return 0;
    if (num == 1) return 1;

    return num * factorial(num - 1);
}