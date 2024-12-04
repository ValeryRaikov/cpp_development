/*
Да се дефинира клас дата описващ дати от календара и включващ подходящи член данни, конструктор с параметри за 
задаване на дата и копиращ конструктор. Да се дефинира клас пациент с член данни: име, егн, оплакване и дата на 
прегледа(да се използва класа за дата). Да се състави главна функция, в която се създава масив от обекти от 
клас Пациент и извежда всички пациенти с дадено оплакване.
*/

// 01 solution
#include <iostream>
#include <string>

using namespace std;

const int N = 5;

class Date {
private:
	int day;
	int month;
	int year;
public:
	Date() {} // default constructor for array initialization!

	Date(int day, int month, int year) {
		this->day = day;
		this->month = month;
		this->year = year;
	}

	Date(Date& date) {
		this->day = date.day;
		this->month = date.month;
		this->year = date.year;
	}

	int getDay() { return day; }
	int getMonth() { return month; }
	int getYear() { return year; }
};

class Patient {
private:
	string name;
	string egn;
	string complaint;
	Date dateOfVisit;
public:
	Patient() {} // default constructor for array initialization!

	Patient(string name, string egn, string complaint, Date dateOfVisit) {
		this->name = name;
		this->egn = egn;
		this->complaint = complaint;
		this->dateOfVisit = dateOfVisit;
	}

	string getName() { return name; }
	string getEgn() { return egn; }
	string getComplaint() { return complaint; }
	Date getDate() { return dateOfVisit; }

	void display() {
		cout << "Patient: " << getName() << ", EGN: " << getEgn() << ", Complaint: " << getComplaint() << endl;
		cout << "Date of visit: " << dateOfVisit.getDay() << '/' << dateOfVisit.getMonth() << '/' << dateOfVisit.getYear() << endl;
	}
};

int main() {
	Patient patients[N];

	string name, egn, complaint;
	int day, month, year;
	for (int i = 0; i < N; ++i) {
		cout << "Enter patient name: ";
		getline(cin , name);
		cout << "Enter patient egn: ";
		getline(cin, egn);
		cout << "Enter complaint: ";
		getline(cin, complaint);
		cout << "Enter date of visit info:\n";
		cout << "Enter day: ";
		cin >> day;
		cout << "Enter month: ";
		cin >> month;
		cout << "Enter year: ";
		cin >> year;
		cin.ignore();

		Date d(day, month, year);
		patients[i] = Patient(name, egn, complaint, d);
	}

	const string search = "Covid";
	cout << "Patients with complaint of " << search << endl;
	for (auto& p : patients) {
		if (p.getComplaint() == search) {
			p.display();
		}
	}

	return 0;
}

// 02 solution
#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int N = 2;

class Date {
private:
	int day;
	int month;
	int year;
public:
	Date() : day(1), month(1), year(2000) {}

	Date(int day, int month, int year) {
		this->day = day;
		this->month = month;
		this->year = year;
	}

	// Date(Date& date) {
	// 	  this->day = date.day;
	// 	  this->month = date.month;
	// 	  this->year = date.year;
	// }

	int getDay() { return day; }
	int getMonth() { return month; }
	int getYear() { return year; }
};

class Patient {
private:
	string name;
	string egn;
	string complaint;
	Date dateOfVisit;
public:
	Patient() : name(""), egn(""), complaint(""), dateOfVisit() {}

	Patient(string name, string egn, string complaint, Date dateOfVisit) {
		this->name = name;
		this->egn = egn;
		this->complaint = complaint;
		this->dateOfVisit = dateOfVisit;
	}

	string getName() { return name; }
	string getEgn() { return egn; }
	string getComplaint() { return complaint; }
	Date getDate() { return dateOfVisit; }

	void display() {
		cout << "Patient: " << getName() << ", EGN: " << getEgn() << ", Complaint: " << getComplaint() << endl;
		cout << "Date of visit: " << dateOfVisit.getDay() << '/' << dateOfVisit.getMonth() << '/' << dateOfVisit.getYear() << endl;
	}
};

int main() {
	vector<Patient> patients;

	string name, egn, complaint;
	int day, month, year;
	for (int i = 0; i < N; ++i) {
		cout << "Enter patient name: ";
		getline(cin , name);
		cout << "Enter patient egn: ";
		getline(cin, egn);
		cout << "Enter complaint: ";
		getline(cin, complaint);
		cout << "Enter date of visit info:\n";
		cout << "Enter day: ";
		cin >> day;
		cout << "Enter month: ";
		cin >> month;
		cout << "Enter year: ";
		cin >> year;
		cin.ignore();

		patients.push_back(Patient(name, egn, complaint, Date(day, month, year)));
	}

	const string search = "Covid";
	cout << "Patients with complaint of " << search << endl;
	for (auto& p : patients) {
		if (p.getComplaint() == search) {
			p.display();
		}
	}

	return 0;
}

// Решение на Чат ГПТ:
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Date {
private:
    int day;
    int month;
    int year;
public:
    // Конструктор с параметри
    Date(int d, int m, int y) : day(d), month(m), year(y) {}

    // Копиращ конструктор
    Date(const Date& other) : day(other.day), month(other.month), year(other.year) {}

    // Методи за достъп
    int getDay() const { return day; }
    int getMonth() const { return month; }
    int getYear() const { return year; }

    // Метод за извеждане
    void display() const {
        cout << day << "/" << month << "/" << year;
    }
};

class Patient {
private:
    string name;
    string egn;
    string complaint;
    Date dateOfVisit;
public:
    // Конструктор с параметри
    Patient(string n, string e, string c, Date d)
        : name(n), egn(e), complaint(c), dateOfVisit(d) {}

    // Методи за достъп
    string getName() const { return name; }
    string getEgn() const { return egn; }
    string getComplaint() const { return complaint; }
    Date getDate() const { return dateOfVisit; }

    // Метод за извеждане
    void display() const {
        cout << "Name: " << name << ", EGN: " << egn << ", Complaint: " << complaint << ", Date of Visit: ";
        dateOfVisit.display();
        cout << endl;
    }
};

int main() {
    const int N = 5; // Размер на масива
    vector<Patient> patients;

    // Въвеждане на данни за пациентите
    for (int i = 0; i < N; ++i) {
        string name, egn, complaint;
        int day, month, year;

        cout << "Enter patient " << i + 1 << " name: ";
        getline(cin, name);

        cout << "Enter EGN: ";
        getline(cin, egn);

        cout << "Enter complaint: ";
        getline(cin, complaint);

        cout << "Enter date of visit (day, month, year): ";
        cin >> day >> month >> year;
        cin.ignore(); // Изчистване на буфера след числов вход

        // Създаване на обект от клас Date и добавяне на пациента в масива
        Date visitDate(day, month, year);
        patients.emplace_back(name, egn, complaint, visitDate);
    }

    // Търсене по оплакване
    string searchComplaint;
    cout << "\nEnter complaint to search: ";
    getline(cin, searchComplaint);

    cout << "\nPatients with complaint \"" << searchComplaint << "\":\n";
    for (const auto& p : patients) {
        if (p.getComplaint() == searchComplaint) {
            p.display();
        }
    }

    return 0;
}