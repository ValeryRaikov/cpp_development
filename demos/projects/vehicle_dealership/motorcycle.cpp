#include <iostream>

#include "vehicle.cpp"

using namespace std;

class Motorcycle : public Vehicle {
private:
    int weight;
    int horsepower;
    int maxSpeed;
public:
    Motorcycle(string brand, string model, int year, int mileage, int price, int weigth, int horsepower, int maxSpeed) {
        initialize(brand, model, year, mileage, price);
        this->weight = weight;
        this->horsepower = horsepower;
        this->maxSpeed = maxSpeed;
    }

    static Motorcycle createMotorcycle() {
        string brand, model;
        int year, mileage, price, weight, horsepower, maxSpeed;

        cout << "Enter brand: ";
        getline(cin, brand);
        cout << "Enter model:";
        getline(cin, model);
        cout << "Enter year of production: ";
        cin >> year;
        cout << "Enter motorcycle mileage: ";
        cin >> mileage;
        cout << "Enter price: ";
        cin >> price;
        cout << "Enter weight: ";
        cin >> weight;
        cout << "Enter horse power: ";
        cin >> horsepower;
        cout << "Enter max speed: ";
        cin >> maxSpeed;

        try {
            return Motorcycle(brand, model, year, mileage, price, weight, horsepower, maxSpeed);
        } catch (const exception& e) {
            cout << "Cannot create motorcycle: " << e.what() << endl;
            exit(1);
        }
    }

    void displayVehicleInfo() override {
        cout << "Vehicle:\n";
        cout << "Motorcycle: " << this->brand << ' ' << this->model << endl;
        cout << "Year: " << this->year << endl;	
        cout << "Mileage: " << this->mileage << endl;
        cout << "Price: " << this->price << endl;
        cout << "Weight: " << weight << "kg\n";
        cout << "Horse power: " << horsepower << endl;
        cout << "Max speed: " << maxSpeed << endl;
    }
};