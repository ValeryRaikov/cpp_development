#include <iostream>

int main() {
    using namespace std;

    string name;
    int age;

    cout << "Enter name: ";
    cin >> name;
    cout << "Age: ";
    cin >> age;

    cout << "Name: " << name << ", " << "Age: " << age << endl;

    string full_name;
    getline(cin >> ws, full_name);
    cout << "Full name: " << full_name << endl;

    return 0;
}