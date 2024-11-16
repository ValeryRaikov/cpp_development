#include <iostream>
#include <vector>
#include <algorithm>

#include "vehicle.cpp"
#include "issue.cpp"
#include "engine_types.cpp"

using namespace std;

class Car : public Vehicle {
private:
    engine engineType;
    string vinNumber;
    vector<Issue> issues;
public:
    Car(string brand, string model, int year, int mileage, int price, engine engineType, string vinNumber) {
        initialize(brand, model, year, mileage, price);
        this->engineType = engineType;
        this->vinNumber = vinNumber;
        this->issues = vector<Issue>();
    }

    static Car createCar() {
        string brand, model, vinNumber;
        int year, mileage, price, engineInput;

        cout << "Enter brand: ";
        getline(cin, brand);
        cout << "Enter model:";
        getline(cin, model);
        cout << "Enter year of production: ";
        cin >> year;
        cout << "Enter car mileage: ";
        cin >> mileage;
        cout << "Enter price: ";
        cin >> price;
        cout << "Enter engine type: (1-diesel, 2-petrol, 3-hybrid, 4-electric) ";
        cin >> engineInput;
        cout << "Enter engine VIN number: ";
        cin.ignore();
        getline(cin, vinNumber);

        engine engineType = static_cast<engine>(engineInput);

        try {
            return Car(brand, model, year, mileage, price, engineType, vinNumber);
        } catch (const exception& e) {
            cout << "Cannot create car: " << e.what() << endl;
            exit(1);
        }
    }

    void addIssue(const Issue& issue) {
        if (find(issues.begin(), issues.end(), issue) != issues.end()) {
            cout << "Issue already added to car.\n";
            return;
        }

        issues.push_back(issue);
        cout << "Issue added successfully.\n";
    }

    void removeIssue(const Issue& issue) {
        auto it = find(issues.begin(), issues.end(), issue);

        if (it == issues.end()) {
            cout << "Issue not present in the car issues' list.\n";
            return;
        }

        issues.erase(it);
        price += issue.price;
        cout << "Issue removed successfully.\n";
    }

    void displayVehicleInfo() override {
        cout << "Vehicle:\n";
        cout << "Car: " << this->brand << ' ' << this->model << endl;
        cout << "Year: " << this->year << endl;	
        cout << "Mileage: " << this->mileage << endl;
        cout << "Price: " << this->price << endl;
        cout << "Engine type: " << engineType << endl;
        cout << "VIN number: " << vinNumber << endl;

        if (issues.empty()) {
            cout << "No current issues.\n";
            return;
        }

        cout << "Issues:\n";
        for (const auto& issue : issues) {
            cout << " -> " << issue << endl;
        }
    }
};