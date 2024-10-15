#include <iostream>

int main() {
    using namespace std;

    string name;
    while (name.empty()) {
        cout << "Enter your name: ";
        getline(cin, name);
    }

    cout << "Hello, " << name << '\n';

    return 0;
}