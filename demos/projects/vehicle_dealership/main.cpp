#include "owner.cpp"
#include "car.cpp"
#include "motorcycle.cpp"

int main() {
    Owner owner("Valery Raikov", "1234567890", 50000);

    auto car = make_shared<Car>("Toyota", "Camry", 2020, 15000, 20000, 2, "VIN123");
    auto motorcycle = make_shared<Motorcycle>("Harley-Davidson", "Sportster", 2018, 5000, 15000, 345, 110, 197);

    owner.buyNewVehicle(car);
    owner.buyNewVehicle(motorcycle);

    cout << owner;

    owner.sellVehicle(car);

    cout << owner;

    return 0;
}
