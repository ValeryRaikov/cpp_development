#include <iostream>

using namespace std;

void swap(string &x, string &y);

int main() {

    string x = "String 1";
    string y = "String 2";
    string temp;

    temp = x;
    x = y;
    y = temp;

    cout << "X: " << x << '\n';
    cout << "Y: " << y << '\n';

    cout << '\n';

    swap(x, y);

    cout << "X: " << x << '\n';
    cout << "Y: " << y << '\n';

    return 0;
}

void swap(string &x, string &y) {
    string temp = x;
    x = y;
    y = temp;
}