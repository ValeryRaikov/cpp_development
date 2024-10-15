#include <iostream>

int main() {
    using namespace std;

    int number;

    /* cout << "Enter a positive number: ";
    cin >> number;
    while (number < 0) {
        cout << "Enter a positive number: ";
        cin >> number;
    }

    cout << "Number is " << number << endl; */

    do {
        cout << "Enter a positive number: ";
        cin >> number;
    } while (number < 0);

    return 0;
}