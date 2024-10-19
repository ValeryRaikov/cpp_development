#include <iostream>

using namespace std;

void print_info(const string name, const int age);

int main() {

    string name = "Valery";
    int age = 21;

    print_info(name, age);

    return 0;
}

void print_info(const string name, const int age) {
    cout << name << ", " << age << endl;
}