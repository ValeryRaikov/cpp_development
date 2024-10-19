#include <iostream>

using namespace std;

class Car {
    public:
        string brand;
        string model;
        int year;
        int mileage;

        void print_vehicle_data() {
            cout << "Vehicle:\n" 
                << brand << ' ' << model << "\nyear: " << year << "\nmileage: " << mileage << '\n';
        }

        int increase_mileage() {
            cout << "Mileage increase by 1000$!\n";

            mileage += 1000;
            return mileage;
        }
};

int main() {
    Car car;
    car.brand = "Mercedes";
    car.model = "S63";
    car.year = 2018;
    car.mileage = 100000;

    car.print_vehicle_data();

    cout << car.mileage << '\n';
    car.increase_mileage();
    cout << car.mileage << '\n';

    return 0;
}