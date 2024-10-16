#include <iostream>

int main() {
    using namespace std;

    string name = "Valery";
    int age = 21;
    bool student = true;

    cout << &name << '\n';
    cout << &age << '\n';
    cout << &student << '\n';

    return 0;
}