#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Diagnose {
private:
	string name;
	string description;
	int level;
public:
	Diagnose() {};

	Diagnose(string name, string description, int level) {
		this->name = name;
		this->description = description;
		this->level = level;
	}

	string getName() { return name; }
	string getDescription() { return description; }
	int getLevel() { return level; }

	void display() {
		cout << "Diagnose:\n";
		cout << "Name: " << getName() << "\nDescription: " << getDescription() << "\nSerious index: " << getLevel() << endl;
	}
};

class Patient {
private:
	string fullName;
	int age;
	vector<string> complaints = {};
	Diagnose diagnose;
public:
	Patient(string fullName, int age) {
		this->fullName = fullName;
		this->age = age;
	}

	string getFullName() { return fullName; }
	int getAge() { return age; }

	void setDiagnose(Diagnose& d) {
		if (diagnose.getName().empty()) {
			diagnose = d;
		}
	}

	void addComplaint(string& comp) {
		if (find(complaints.begin(), complaints.end(), comp) != complaints.end()) {
			cout << "Complaint " << comp << " is already added.\n";
			return;
		}

		complaints.push_back(comp);
		cout << "Complaint " << comp << " added successfully.\n";
	}

	void assignDiagnose(Diagnose& d) {
		setDiagnose(d);
	}

	void assignDiagnose() {
		string name, description;
		int level;

		cout << "Enter diagnose name: ";
		cin >> name;
		cin.ignore();
		cout << "Enter diagnose description: ";
		getline(cin, description);
		cout << "Enter diagnose serious index: ";
		cin >> level;

		Diagnose d(name, description, level);
		setDiagnose(d);
	}

	void displayData() {
		cout << "Patient:\n";
		cout << getFullName() << " - " << getAge() << endl;

		if (complaints.empty()) {
			cout << "No complaints added yet.\n";
		}
		else {
			cout << "Complaints:\n";
			for (const auto& comp : complaints) {
				cout << comp << endl;
			}
		}

		if (diagnose.getName().empty()) {
			cout << "No diagnose added yet.\n";
		}
		else {
			diagnose.display();
		}
	}
};

int main() {
	Diagnose d1("Covid", "Serious covid infection and severe flue", 7);

	Patient p1("Ivaylo Raikov", 53);
	Patient p2("Viktora Popova", 26);
	Patient p3("Qnko Stamenov", 42);

	string comp1 = "flue";
	string comp2 = "temperature";
	string comp3 = "sore throat";
	p1.addComplaint(comp1);
	p1.addComplaint(comp2);
	p1.addComplaint(comp3);
	p1.assignDiagnose(d1);
	p1.displayData();
	cout << endl;

	p2.addComplaint(comp3);
	p2.addComplaint(comp3);
	p2.assignDiagnose();
	p2.displayData();
	cout << endl;

	p3.displayData();

	return 0;
}