#include <iostream>

using namespace std;

double get_total(double prices[], int size);

int main() {
    double prices[] = {50.5, 19.99, 35.5, 100};
    int size = sizeof(prices)/sizeof(prices[0]);

    double total = get_total(prices, size);

    cout << "Total value is : " << total << endl;

    return 0;
}

double get_total(double prices[], int size) {
    double total = 0;

    for (int i = 0; i < size; i++) {
        total += prices[i];
    }

    return total;
}