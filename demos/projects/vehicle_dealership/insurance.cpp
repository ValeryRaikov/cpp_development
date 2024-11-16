#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>

#include "vehicle.cpp"
#include "issue.cpp"

using namespace std;

class Insurance {
private:
    string name;
    int pricePercentage;
    int allowedRepairs;
    vector<Vehicle> vehicles;
public:
    Insurance(string name, int pricePercentage, int allowedRepairs) {
        this->name = name;
        this->pricePercentage = pricePercentage;
        this->allowedRepairs = allowedRepairs;
        this->vehicles = vector<Vehicle>();
    }

    void addVehicle(shared_ptr<Vehicle> vehicle) {
        if (find(vehicles.begin(), vehicles.end(), vehicle) != vehicles.end()) {
            cout << "Vehicle is already in the insurance vehicles' list.\n";
            return;
        }

        vehicles.push_back(vehicle);
        vehicle->price += (vehicle->price * pricePercentage / 100);
        cout << "Vehicle added to insurance company " << name << " successfully.\n";
    }

    void removeVehicle(shared_ptr<Vehicle> vehicle) {
        auto it = find(vehicles.begin(), vehicles.end(), vehicle);

        if (it == vehicles.end()) {
            cout << "Vehicle not in the insurance vehicles' list.\n";
            return;
        } 

        vehicles.erase(it);
        vehicle->price -= (vehicle->price * pricePercentage / 100);
        cout << "Successfully removed vehicle: " << vehicle->displayVehicleInfo();
    }

    void repairVehicle(shared_ptr<Vehicle> vehicle, const Issue& issue) {
        if (find(vehicles.begin(), vehicles.end(), vehicle) == vehicles.end()) {
            cout << "Vehicle not in the insurance vehicles' list.\n";
            return;
        }

        if (vehicle->issues.empty()) {
            cout << "Vehicle has no issues for repair.\n";
            return;
        }

        vehicle->removeIssue(issue);
    }
 
    friend ostream& operator<<(ostream& os, const Insurance& insurance) {
        os << "Insurance company: " << insurance.name << endl;
        os << "Price percentage: " << insurance.pricePercentage << endl;
        os << "Allowed repairs: " << insurance.allowedRepairs << endl;

        if (insurance.vehicles.empty()) {
            os << "No vehicles added yet.\n";
            return;
        }

        os << "Vehicles:\n";
        for (const auto& vehicle : insurance.vehicles) {
            os << " -> " << vehicle.displayVehicleInfo();
        }
    }
};