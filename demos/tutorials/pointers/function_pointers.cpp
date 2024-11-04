#include <iostream>

using namespace std;

int getNumber() {
    return 5;
}

int add(int a, int b) {
    return a + b;
}

int main() {
    int(*funcPtr)() = getNumber;
    cout << funcPtr() << endl;

    int(*funcPtr2)(int, int) = add;
    cout << funcPtr2(3, 4);

    return 0;
}