#include <iostream>

int main() {
    using namespace std;

    string cars[][3] = {
        {"Mustang", "Fiesta", "Mondeo"},
        {"Octavia", "Superb", "Kodiaq"},
        {"A8", "Q7", "RS6"}
    };

    cout << cars[2][1] << '\n';

    int rows = sizeof(cars) / sizeof(cars[0]);
    int cols = sizeof(cars[0]) / sizeof(cars[0][0]);

    cout << "All cars:" << '\n';
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << cars[i][j] << ", ";
        }
        cout << '\n';
    }

    return 0;
}