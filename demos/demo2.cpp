#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

class Repair {
private:
    string issue;
    int durationDays;
    double costs;
public:
    Repair(string issue, int durationDays, double costs) {
        this->issue = issue;
        this->durationDays = durationDays;
        this->costs = costs;
    }

    string getIssue() { return issue; }
    void setIssue(string newIssue) { issue = newIssue; }
    int getDurationDays() { return durationDays; }
    void setDurationDays(int newDurationDays) { durationDays = newDurationDays; }
    double getCost() { return costs; }
    void setCost(double newCosts) { costs = newCosts; }

    static Repair createRepair() {
        string issue;
        int durationDays;
        double costs;

        cout << "Enter vehicle issue: ";
        cin.ignore();
        getline(cin, issue);
        cout << "Enter repair duration days: ";
        cin >> durationDays;
        cout << "Enter repair costs: ";
        cin >> costs;

        return Repair(issue, durationDays, costs);
    }

    friend ostream& operator<<(ostream& os, const Repair& repair) {
        os << "Issue: " << repair.issue << ", Duration: " << repair.durationDays << " days, Cost: $" << repair.costs;
        return os;
    }

    bool operator==(const Repair& other) const {
        return issue == other.issue && durationDays == other.durationDays && costs == other.costs;
    }
};

class Vehicle {
protected:
    string brand;
    string model;
    int year;
    int mileage;
    double price;
public:
    virtual void addRepair(Repair) = 0;
    virtual void removeRepair(Repair) = 0;
    virtual void printInfo() = 0;

    string getBrand() { return brand; }
    void setBrand(string newBrand) { brand = newBrand; }
    string getModel() { return model; }
    void setModel(string newModel) { model = newModel; }
    int getYear() { return year; }
    void setYear(int newYear) { year = newYear; }
    int getMileage() { return mileage; }
    void setMileage(int newMileage) { mileage = newMileage; }
    double getPrice() { return price; }
    void setPrice(double newPrice) { price = newPrice; }
};

class Car : public Vehicle {
private:
    string fuelType;
    vector<Repair> repairs;
public:
    Car(string brand, string model, int year, int mileage, double price, string fuelType, vector<Repair> repairs) {
        this->brand = brand;
        this->model = model;
        this->year = year;
        this->mileage = mileage;
        this->price = price;
        this->fuelType = fuelType;
        this->repairs = {};
    }

    string getFuelType() { return fuelType; }
    void setFuelType(string newFuelType) { fuelType = newFuelType; }
    vector<Repair> getRepairs() { return repairs; }

    static Car createCar() {
        string brand, model, fuelType;
        int year, mileage;
        double price;
        vector<Repair> repairs;

        cout << "Enter brand: ";
        cin.ignore();
        getline(cin, brand);

        cout << "Enter model: ";
        getline(cin, model);

        cout << "Enter year: ";
        cin >> year;

        cout << "Enter mileage: ";
        cin >> mileage;

        cout << "Enter price: ";
        cin >> price;

        cout << "Enter fuel type: ";
        cin.ignore();
        getline(cin, fuelType);

        int repairCount;
        cout << "Enter number of repairs: ";
        cin >> repairCount;
        for (int i = 0; i < repairCount; ++i) {
            repairs.push_back(Repair::createRepair());
        }

        return Car(brand, model, year, mileage, price, fuelType, repairs);
    }

    void addRepair(Repair repair) {
        if (find(getRepairs().begin(), getRepairs().end(), repair) != getRepairs().end()) {
            cout << "Repair already in the list!\n";
            return;
        }

        repairs.emplace_back(repair);
    }

    void removeRepair(Repair repair) {
        auto it = find(getRepairs().begin(), getRepairs().end(), repair);
        if (it == getRepairs().end()) {
            cout << "Repair is not in the list!\n";
            return;
        }

        repairs.erase(it);
    }

    double minRepairPrice() {
        if (repairs.empty()) {
            return 0;
        }

        double minPrice = numeric_limits<double>::max();

        for (Repair repair: getRepairs()) {
            if (repair.getCost() < minPrice) {
                minPrice = repair.getCost();
            }
        }

        return minPrice;
    }

    double maxRepairPrice() {
        if (repairs.empty()) {
            return 0;
        }

        double maxPrice = numeric_limits<double>::lowest();

        for (Repair repair: getRepairs()) {
            if (repair.getCost() > maxPrice) {
                maxPrice = repair.getCost();
            }
        }

        return maxPrice;
    }

    double avgRepairPrice() {
        if (repairs.empty()) {
            return 0;
        }

        int total;
        double totalCosts, average;

        for (Repair repair: getRepairs()) {
            totalCosts += repair.getCost();
            total++;
        }

        average = totalCosts / total;

        return average;
    }

    void printInfo() {
        cout << "Car Information:\n";
        cout << "Brand: " << getBrand() << endl;
        cout << "Model: " << getModel() << endl;
        cout << "Year: " << getYear() << endl;
        cout << "Mileage: " << getMileage() << endl;
        cout << "Price: $" << getPrice() << endl;
        cout << "Fuel type: " << getFuelType() << endl;

        if (repairs.empty()) {
            cout << "No repairs!\n";
        } else {
            cout << "Repairs:\n";
            for (const Repair& repair : repairs) {
                cout << "-> " << repair << endl;
            }
        }
    }

    ~Car() {}
};

int main() {
    // Car car1 = Car::createCar();
    // car1.printInfo();

    Repair rep1 = Repair::createRepair();
    // cout << rep1;
    Repair rep2 = Repair("Oil Change", 1, 200);

    Car car2 = Car("Audi", "A6", 2019, 135000, 24999.99, "diesel", {});

    car2.addRepair(rep1);
    car2.addRepair(rep2);
    car2.printInfo();

    car2.removeRepair(rep1);
    car2.printInfo();

    cout << "Minimal repair price: " << car2.minRepairPrice() << endl;
    cout << "Maximal repair price: " << car2.maxRepairPrice() << endl;
    cout << "Average repair price: " << car2.avgRepairPrice() << endl;

    return 0;
}
