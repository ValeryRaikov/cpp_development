#include <iostream>

int main() {
    using namespace std;

    string cars[] = {"Volvo", "VW", "Skoda", "Mercedes"};

    int num_cars = sizeof(cars) / sizeof(cars[0]);

    for (int i = 0; i < num_cars; i++) {
        cout << "Brand -> " << cars[i] << endl;
    }

    string names[3];
    names[0] = "Valery";
    names[1] = "Magdalena";
    names[2] = "Ivaylo";

    cout << "Name: " << names[0] << endl;

    return 0;
}