#include <iostream>

int total_sum(int a, int b);

using namespace std;

int main() {
    int a, b;
    cout << "Enter value for a: ";
    cin >> a;
    cout << "Enter value for b: ";
    cin >> b;

    cout << "The sum of " << a << " and " << b << " is " << total_sum(a, b) << endl;

    return 0;
}

int total_sum(int a, int b) {
    return a + b;
}