#include <iostream>

using namespace std;

void happy_birthday(string name);

int main() {
    string name;

    while (name.empty()) {
        cout << "Enter your name: ";
        getline(cin, name);
    }

    happy_birthday(name);

    return 0;
}

void happy_birthday(string name) {
    cout << "Happy birthday to you, " << name << endl;
}