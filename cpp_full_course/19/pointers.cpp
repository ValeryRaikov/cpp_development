#include <iostream>

int main() {
    using namespace std;

    string name = "Valery";
    string *p_name = &name;

    cout << "Address: " << p_name << endl;
    cout << "Value: " << *p_name << endl;

    cout << "Address: " << &name << endl;
    cout << "Value: " << name << endl;

    /* int age = 21;
    int *p_age = &age; */

    string cars[5] = {"Skoda", "VW", "BMW", "Renault", "Toyota"}; 
    string *p_cars = cars;

    cout << *p_cars << endl;  // first array element

    return 0;
}