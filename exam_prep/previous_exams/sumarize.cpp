// Fahrenheit to celsius calculator
#include <iostream>

using namespace std;

class Temperature {
protected:
	double temp;
public:
	Temperature(double temp) {
		this->temp = temp;
	}

	double getTemperature() { return temp; }

	virtual double convertTemp() = 0;
};

class FahrToCel : public Temperature {
public:
	FahrToCel(double temp) : Temperature(temp) {};

	double convertTemp() override {
		double tempInCel = (5.0 / 9.0) * (temp - 32);
		return tempInCel;
	}
};

int main() {
	FahrToCel t1(50.5);
	cout << "Entered temp: " << t1.getTemperature() << "F\n";

	FahrToCel t2(73.4);
	cout << "Entered temp: " << t2.getTemperature() << "F\n";
	double temp = t2.convertTemp();
	cout << "Tempreture converted to celsius is: " << temp << "C\n";

	return 0;
}

// dates and patient visits
#include <iostream>
#include <vector>

using namespace std;

class Date {
private:
	int day;
	int month;
	int year;
public:
	Date(int d, int m, int y) : day(d), month(m), year(y) {};

	int getDay() { return day; }
	int getMonth() { return month; }
	int getYear() { return year; }
};

class Patient {
private:
	string egn;
	string name;
	vector<string> complaints;
	Date visitDate;
public:
	Patient(string e, string n, vector<string> c, Date vd) : egn(e), name(n), complaints(c), visitDate(vd) {};

    // Copy Constructor
    Patient(const Patient& other)
        : egn(other.egn), name(other.name), complaints(other.complaints), visitDate(other.visitDate) {};

	string getEgn() { return egn; }
	string getName() { return name; }
	vector<string> getComplaints() { return complaints; }
	Date getVisitDate() { return visitDate; }
};

int main() {
	Date d1(1, 10, 2023);
	Date d2(12, 6, 2024);
	Date d3(25, 11, 2024);
	vector<Date> dates = {d1, d2, d3};

	Patient p1("123456", "Valery", { "headache", "stomachache" }, dates[0]);
	Patient p2("654321", "Ivan", { "headache", "injury" }, dates[1]);
	Patient p3("001122", "Maria", { "ilness", "vertigio" }, dates[2]);
	vector<Patient> patients = {p1, p2, p3};

	const string complaint = "headache";

	cout << "Patients with complaints of " << complaint << endl;
	for (auto& p : patients) {
		for (auto& comp : p.getComplaints()) {
			if (comp == complaint) {
				cout << "Patient: " << p.getName() << " - " << p.getEgn() << endl;
			}
		}
	}

	return 0;
}

// must see also ./previous_exams/ -03.cpp; -04.cpp; -06.cpp -07.cpp