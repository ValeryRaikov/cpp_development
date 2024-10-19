#include <iostream>

using namespace std;

struct Car {
    string brand;
    string model;
    int year;
    string color;
};

void print_car(Car &car);

int main() {

    Car car1;
    Car car2;

    car1.brand = "Skoda";
    car1.model = "Octavia";
    car1.year = 2015;
    car1.color = "brown";

    car2.brand = "Audi";
    car2.model = "A8";
    car2.year = 2020;
    car2.color = "black";

    print_car(car1);
    print_car(car2);

    return 0;
}

void print_car(Car &car) {
    cout << "Car:\n" << car.brand << " " << car.model << '\n' << car.year << '\n' << car.color << '\n';
}