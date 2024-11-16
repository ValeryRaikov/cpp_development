#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>

#include "vehicle.cpp"

using namespace std;

class Owner {
private:
    string fullName;
    string egn;
    int budget;
    vector<shared_ptr<Vehicle>> vehicles;
public:
    Owner(string fullName, string egn, int budget) {
        this->fullName = fullName;
        this->egn = egn;
        this->budget = budget;
        this->vehicles = vector<Vehicle>();
    }

    void buyNewVehicle(shared_ptr<Vehicle> vehicle) {
        if (find(vehicles.begin(), vehicles.end(), vehicle) != vehicles.end()) {
            cout << "Vehicle is already in the owner vehicles' list.\n";
            return;
        }

        if (vehicle->price > budget) {
            cout << "Owner budget is insufficient.\n";
            return;
        }

        vehicles.push_back(vehicle);
        budget -= vehicle->price;
        cout << "Successfully bought vehicle: " << vehicle->displayVehicleInfo();
    }

    void sellVehicle(shared_ptr<Vehicle> vehicle) {
        auto it = find(vehicles.begin(), vehicles.end(), vehicle);

        if (it == vehicles.end()) {
            cout << "Vehicle not in the owner vehicles' list.\n";
        }

        vehicles.erase(it);
        budget += vehicle->price;
        cout << "Successfully sold vehicle: " << vehicle->displayVehicleInfo();
    }

    friend ostream& operator<<(ostream& os, const Owner& owner) {
        os << "Owner: " << owner.fullName << endl;
        os << "EGN: " << owner.egn << endl;
        os << "Budget: " << owner.budget << endl;

        if (owner.vehicles.empty()) {
            os << "Owner " << owner.fullName << " has no vehicles yet.\n";
            return;
        }

        os << "Vehicles:\n";
        for (const auto& vehicle : owner.vehicles) {
            cout << " -> " << vehicle->displayVehicleInfo();
        }

        return os;
    }
};