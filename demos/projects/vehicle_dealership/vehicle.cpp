#include <iostream>

using namespace std;

class Owner;
class Insurance;

class Vehicle {
protected:
    string brand;
    string model;
    int year;
    int mileage;
    int price;
public:
    void initialize(string brand, string model, int year, int mileage, int price) {
        this->brand = brand;
        this->model = model;
        this->year = year;
        this->mileage = mileage;
        this->price = price;
    }

    bool operator==(const Vehicle& other) const {
        return brand == other.brand &&
               model == other.model &&
               year == other.year &&
               mileage == other.mileage &&
               price == other.price;
    }
    virtual void displayVehicleInfo() = 0;

    friend class Owner;
    friend class Insurance;
};