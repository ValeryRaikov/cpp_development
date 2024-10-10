#include <iostream>

int main() {
    using namespace std;

    int a = 50;
    a += 10;

    cout << a << '\n';

    int sum = a + 100;

    cout << sum << '\n';

    int b = 20;

    int sub = a - b;
    int mult = a * b;
    double div = a / b;

    cout << "Sum: " << sum << '\n' << "Mult: " << mult << '\n' << "Div: " << div << '\n';

    return 0;
}