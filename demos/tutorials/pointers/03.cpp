#include <iostream>

using namespace std;

int main() {
    /*
    int luckyNumbers[5] = {3, 7, 9, 12, 17};
    cout << luckyNumbers << endl;
    cout << &luckyNumbers[0] << endl;

    cout << luckyNumbers[2] << endl;
    cout << *(luckyNumbers+2) << endl;
    */

    int luckyNumbers[5];
    for (int i = 0; i < 5; i++) {
        cout << "Number #1: ";
        cin >> luckyNumbers[i];
    }

    cout << "Numbers:\n";
    for (int i = 0; i < 5; i++) {
        cout << *(luckyNumbers + i) << ' ';
    }

    return 0;
}