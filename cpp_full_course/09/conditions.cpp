#include <iostream>

int main() {
    using namespace std;

    int age;

    cout << "Enter your age: " << endl;
    cin >> age;

    if (age < 0 || age > 100) {
        cout << "Invalid user input!";
    } else if (age < 18) {
        cout << "You are immature";
    } else {
        cout << "You are mature";
    }

    return 0;
}