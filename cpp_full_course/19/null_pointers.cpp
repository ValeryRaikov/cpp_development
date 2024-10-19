#include <iostream>

int main() {
    using namespace std;

    int *pointer = nullptr;
    int x = 123;

    pointer = &x;

    if (pointer == nullptr) {
        cout << "Error with address assignment" << endl;
        return -1;
    }

    cout << "Address assignment is successful" << endl;
    cout << "Address: " << pointer << endl;
    cout << "Value: " << *pointer << endl;

    return 0;
}