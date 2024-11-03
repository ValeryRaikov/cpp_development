#include <iostream>

using namespace std;

int main() {
    int n = 5;
    cout << &n << endl;

    int* ptr = &n;
    cout << ptr << endl;
    cout << *ptr << endl;

    *ptr = 10;
    cout << *ptr << endl;
    cout << n << endl;

    int* ptr2 = nullptr;
    ptr2 = ptr;
    cout << ptr2 << endl;
    cout << *ptr2 << endl;  

    return 0;
}