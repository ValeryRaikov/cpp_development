#include <iostream>

using namespace std;

class Issue {
private:
    string name;
    string description;
    int repairDuration;
    int price;
public:
    Issue(string name, string description, int repairDuration, int price) {
        this->name = name;
        this->description = description;
        this->repairDuration = repairDuration;
        this->price = price;
    }

    bool operator==(const Issue& other) const {
        return name == other.name &&
               description == other.description &&
               repairDuration == other.repairDuration &&
               price == other.price;
    }

    friend ostream& operator<<(ostream& os, const Issue& issue) {
        os << "Vehicle issue: " << issue.name << endl;
        os << "Description: " << issue.description << endl;
        os << "Repair estimated duration: " << issue.repairDuration << endl;
        os << "Estimated price: " << issue.price << endl;

        return os;
    }
};