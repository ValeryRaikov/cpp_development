#include <iostream>

int main() {
    using namespace std;

    const int temp = 20;
    if (temp > 0 && temp < 30 || temp == 20) {
        cout << "Testing temperature..." << endl;
    } else {
        cout << "Oops..." << endl;
    }

    bool is_hungry = false;
    cout << !is_hungry << endl;

    return 0;
}