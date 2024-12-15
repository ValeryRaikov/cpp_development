// 01
#include <iostream>

using namespace std;

const double MATH_PI = 3.1415;

class Volume {
private:
	double radius;
public:
	Volume(double radius) {
		this->radius = radius;
	}

	double getRadius() { return radius; }
	void setRadius(double value) {
		if (value > 0) {
			radius = value;
		}
	}

	virtual double calculateVolume() = 0;
};

class Sphere : public Volume {
public:
	Sphere(double radius) : Volume(radius) {};

	double calculateVolume() override {
		return (4.0 / 3.0) * MATH_PI* getRadius()* getRadius()* getRadius();
	}
};

int main() {
	Sphere s1(4.5);
	Sphere s2(7.69);

	cout << "Sphere 1 volume is: " << s1.calculateVolume() << endl;
	cout << "Sphere 2 volume is: " << s2.calculateVolume() << endl;

	if (s1.getRadius() > s2.getRadius())
		cout << "Bigger radius is: " << s1.getRadius() << endl;
	else if (s2.getRadius() > s1.getRadius())
		cout << "Bigger radius is: " << s2.getRadius() << endl;
	else
		cout << "Radiuses are equal...\n";

	return 0;
}

// 02
#include <iostream>

using namespace std;

class Employee {
protected:
	string name;
	int id;
public:
	Employee(string name, int id) {
		this->name = name;
		this->id = id;
	}

	string getName() const { return name; }
	int getId() const { return id; }

	virtual double calculateSalary() = 0;
	virtual void displayInfo() const = 0;
};

class RegularEmployee : public Employee {
protected:
	double baseSalary;
public:
	RegularEmployee(string name, int id, double baseSalary) : Employee(name, id) {
		this->baseSalary = baseSalary;
	}

	double getBaseSalary() const { return baseSalary; }

	double calculateSalary() override {
		return baseSalary * 12;
	}

	void displayInfo() const override {
		cout << "Regular Employee: " << getName() << ", " << getId() << ", " << getBaseSalary() << endl;
	}
};

class Manager : public RegularEmployee {
protected:
	double bonus;
public:
	Manager(string name, int id, double baseSalary, double bonus) : RegularEmployee(name, id, baseSalary) {
		this->bonus = bonus;
	}

	double getBonus() const { return bonus; }

	double calculateSalary() override {
		return baseSalary * 12 + bonus * 12;
	}

	void displayInfo() const override {
		cout << "Manager: " << getName() << ", " << getId() << ", " << getBaseSalary() << ", " << getBonus() << endl;
	}
};

int main() {
	Employee* employees[4] = {};

	employees[0] = new RegularEmployee("Valery", 1, 1800);
	employees[1] = new RegularEmployee("Ivaylo", 2, 2500);
	employees[2] = new Manager("Meggie", 3, 4200.99, 150);
	employees[3] = new Manager("Dimitar", 4, 3750.75, 180);

	for (const auto& emp : employees) {
		emp->displayInfo();
		cout << "Total salary: " << emp->calculateSalary() << endl;
	}

	double biggestSalary = 0;
	Employee* highestPaid = nullptr;
	for (const auto& emp : employees) {
		if (emp->calculateSalary() > biggestSalary) {
			biggestSalary = emp->calculateSalary();
			highestPaid = emp;
		}
	}

	if (highestPaid) {
		cout << "Highest paid employee is: " << highestPaid->getName()
			<< " with a salary of " << biggestSalary << endl;
	}

	for (int i = 0; i < 4; ++i) {
		delete employees[i];
	}

	return 0;
}

// 03
#include <iostream>
#include <vector>

using namespace std;

class Date {
private:
	int day, month, year;
public:
	Date(int d, int m, int y) : day(d), month(m), year(y) {};

	Date(const Date& other) : day(other.day), month(other.month), year(other.year) {};

	int getDay() const { return day; }
	int getMonth() const { return month; }
	int getYear() const { return year; }

	void displayDate() const {
		cout << getDay() << '-' << getMonth() << '-' << getYear() << endl;
	}
};

class Book {
private:
	string title;
	string author;
	string borrower;
	Date borrowedDate;
public:
	Book(string t, string a, string b, Date bd) : title(t), author(a), borrower(b), borrowedDate(bd) {};

	string getTitle() const { return title; }
	string getAuthor() const { return author; }
	string getBorrower() const { return borrower; }
	Date getBorrowedDate() const { return borrowedDate; }

	bool isBorrowed() const {
		return !getBorrower().empty();
	}

	void displayBookInfo() const {
		cout << "Book:\n";
		cout << "Title: " << getTitle() << endl;
		cout << "Author: " << getAuthor() << endl;
		cout << "Borrower: " << getBorrower() << endl;
		cout << "Borrowed date: ";
		getBorrowedDate().displayDate();
	}
};

int main() {
	vector<Book> books = {
		Book("T1", "A1", "B1", Date(1, 10, 2024)),
		Book("T2", "A2", "B2", Date(10, 10, 2024)),
		Book("T3", "A1", "", Date(25, 11, 2024)),
		Book("T4", "A3", "B3", Date(30, 11, 2024)),
		Book("T5", "A4", "", Date(12, 12, 2024)),
	};

	string author;
	cout << "Enter author to search for: ";
	cin >> author;

	string message;
	for (auto& b : books) {
		if (b.getAuthor() == author) {
			b.displayBookInfo();
			message = b.isBorrowed() ? "Book is borrowed.\n" : "Book is not borrowed yet.\n";
			cout << message;
		}
	}

	return 0;
}

// 04
#include <iostream>

using namespace std;

class Person {
protected:
	string name;
	string egn;
public:
	Person(string n, string e) : name(n), egn(e) {};

	string getName() const { return name; }
	string getEgn() const { return egn; }
};

class Employee : public Person {
protected:
	string jobTitle;
	int monthlySalary;
public:
	Employee(string n, string e, string jt, int ms) : Person(n, e), jobTitle(jt), monthlySalary(ms) {};

	string getJobTitle() const { return jobTitle; }
	int getMonthlySalary() const { return monthlySalary; }
};

class Manager : public Employee {
protected:
	int bonus;
public:
	Manager(string n, string e, string jt, int ms, int b) : Employee(n, e, jt, ms) {
		if (getMonthlySalary() > 3000) {
			bonus = b;
		}
		else {
			bonus = 0;
		}
	};

	int getBonus() const { return bonus; }
};

int main() {
	Person p("Ivan", "1234");

	Employee e("Valery", "4321", "software developper", 2200);
	cout << e.getName() << endl;
	cout << e.getEgn() << endl;
	cout << e.getJobTitle() << endl;
	cout << e.getMonthlySalary() << endl;

	Manager m1("Maria", "1122", "lead manager", 4500, 300);
	cout << "Bonus: " << m1.getBonus() << endl;

	Manager m2("Petar", "2211", "fleet manager", 2500, 400);
	cout << "Bonus: " << m2.getBonus() << endl;

	return 0;
}

// 05
#include <iostream>

using namespace std;

const int YEAR = 2024;
const int BONUS = 500;

class Individual {
protected:
	string name;
	int yearOfBirth;
public:
	Individual(string name, int yearOfBirth) {
		this->name = name;
		this->yearOfBirth = yearOfBirth;
	}

	int calculateAge() const {
		return YEAR - yearOfBirth;
	}

	void displayInfo() const {
		cout << name << ", " << calculateAge() << endl;
	}
};

class Worker :public Individual {
protected:
	string jobPosition;
	int hourlyWage;
public:
	Worker(string name, int yearOfBirth, string jobPosition, int hourlyWage) : Individual(name, yearOfBirth) {
		this->jobPosition = jobPosition;
		this->hourlyWage = hourlyWage;
	}

	int calculateMonthlyWage() const {
		return hourlyWage * 160;
	}

	void displayInfo() const {
		cout << name << ", " << yearOfBirth << ", " << jobPosition << ", " << calculateMonthlyWage() << endl;
	}
};

class Freelancer : public Worker {
protected:
	int completedProjects;
public:
	Freelancer(string name, int yearOfBirth, string jobPosition, int hourlyWage, int completedProjects)
		: Worker(name, yearOfBirth, jobPosition, hourlyWage) {
		this->completedProjects = completedProjects;
	}

	int calculateBonuses() const {
		return completedProjects * BONUS;
	}

	int calculateMonthlyWage() const {
		return hourlyWage * 160 + calculateBonuses();
	}

	void displayInfo() const {
		cout << name << ", " << yearOfBirth << ", " << jobPosition << ", " << calculateMonthlyWage() << ", " << completedProjects << endl;
	}
};

int main() {
	Individual* individuals[5] = {};
	individuals[0] = new Individual("I1", 2001);
	individuals[1] = new Worker("W1", 2002, "programmer", 15);
	individuals[2] = new Worker("W2", 1984, "accountant", 12);
	individuals[3] = new Freelancer("F1", 2004, "content creator", 16, 2);
	individuals[4] = new Freelancer("F2", 1997, "influencer", 10, 7);

	cout << "List of individuals:\n";
	for (const auto& i : individuals) {
		i->displayInfo();
	}

	for (int i = 0; i < 5; i++) {
		delete individuals[i];
	}

	return 0;
}

// 06
#include <iostream>
#include <vector>

using namespace std;

class Engine {
private:
	string vinNumber;
	string fuelType;
	int numberOfCylinders;
	int horsePower;
public:
	Engine() = default;

	Engine(string vinNumber, string fuelType, int numberOfCylinders, int horsePower) {
		this->vinNumber = vinNumber;
		this->fuelType = fuelType;
		this->numberOfCylinders = numberOfCylinders;
		this->horsePower = horsePower;
	}

	string getVinNumber() const { return vinNumber; }
	string getFuelType() const { return fuelType; }
	int getNumberOfCylinders() const { return numberOfCylinders; }
	int getHorsePower() const { return horsePower; }
};

class Vehicle {
protected:
	string brand;
	string model;
	int year;
	Engine engine;
public:
	Vehicle(string brand, string model, int year, Engine engine) {
		this->brand = brand;
		this->model = model;
		this->year = year;
		this->engine = engine;
	}

	string getBrand() const { return brand; }
	string getModel() const { return model; }
	int getYear() const { return year; }
	Engine getEngine() const { return engine; }


	virtual void displayInfo() const = 0;
};

class Car : public Vehicle {
protected:
	int price;
	bool forSale;
public:
	Car(string brand, string model, int year, Engine engine, int price, bool forSale)
		: Vehicle(brand, model, year, engine) {
		this->price = price;
		this->forSale = forSale;
	}

	int getPrice() const { return price; }
	bool getForSale() const { return forSale; }

	void putOnSale() {
		cout << "Car is now on sale.\n";
		forSale = true;
	}

	void removeFromSale() {
		cout << "Car is removed from sale market.\n";
		forSale = false;
	}

	void displayInfo() const override {
		cout << "Car: " << getBrand() << ' ' << getModel() << endl;
		cout << "Year: " << getYear() << endl;
		cout << "Engine:\n";
		cout << "	VIN number: " << engine.getVinNumber() << endl;
		cout << "	Fuel type: " << engine.getFuelType() << endl;
		cout << "	Horse power: " << engine.getHorsePower() << endl;
		cout << "Price: " << getPrice() << endl;
		string text = getForSale() ? "Car is for sale.\n" : "Car is not for sale yet.\n";
		cout << text << endl;
	}
};

int main() {	
	vector<Car> cars = {};

	cars.push_back(Car("Skoda", "Octavia", 2015, Engine("1234abc", "diesel", 4, 150), 15000, false));
	cars.push_back(Car("BMW", "E60", 2008, Engine("4567abc", "diesel", 6, 240), 11000, true));
	cars.push_back(Car("Mazda", "CX3", 2018, Engine("4321bca", "petrol", 4, 130), 18000, true));
	cars.push_back(Car("Audi", "A6", 2016, Engine("4321def", "petrol", 6, 320), 28000, false));
	cars.push_back(Car("Ford", "Mondeo", 2020, Engine("4365aac", "diesel", 4, 170), 22000, true));

	for (const auto& car : cars) {
		if (car.getForSale()) {
			car.displayInfo();
		}
	}

	return 0;
}

// 07
#include <iostream>

using namespace std;

class Vehicle {
protected:
	string regnNum;
	string model;
	int year;
public:
	// default constructor
	Vehicle() = default;

	// parametrized constructor using listing
	Vehicle(string rn, string m, int y) : regnNum(rn), model(m), year(y) {};

	// dynamic constructor
	// Vehicle() {
	// 	  cout << "Enter reg number: ";
	// 	  cin >> regnNum;
	// 	  cout << "Enter model: ";
	// 	  cin >> model;
	// 	  cout << "Enter year: ";
	// 	  cin >> year;
	// }

	// copy constructor
	Vehicle(const Vehicle& other) : regnNum(other.regnNum), model(other.model), year(other.year) {};

	int getYear() const { return year; }

	void checkIsOlderThan10Years() const {
		if (2024 - year > 10) 
			cout << "Vehicle is older than 10years.\n";
		else
			cout << "Vehicle is younger than 10years.\n";
	}

	void displayInfo() const {
		cout << "Vehicle info:\n";
		cout << regnNum << ", " << model << ", " << year << endl;
	}
};

class Car : public Vehicle {
protected:
	string fuelType;
	double fuelConsumption;
public:
	Car(string rn, string m, int y, string ft, double fc) : Vehicle(rn, m, y), fuelType(ft), fuelConsumption(fc) {};

	double checkFuelConsumption(int distance) const {
		return fuelConsumption * distance / 100;
	}

	void displayInfo() const {
		cout << "Car info:\n";
		cout << regnNum << ", " << model << ", " << year << ", " << fuelType << ", " << fuelConsumption << endl;
	}
};

class Truck : public Vehicle {
protected:
	int capacity;
	int currentCapacity;
public:
	Truck(string rn, string m, int y, int c, int cc) : Vehicle(rn, m, y), capacity(c), currentCapacity(cc) {};

	bool isOverweightCapacity() const {
		return currentCapacity > capacity;
	}

	void displayInfo() const {
		cout << "Truck info:\n";
		cout << regnNum << ", " << model << ", " << year << ", " << capacity << ", " << currentCapacity << endl;
		string text = isOverweightCapacity() ? "Overweight capacity.\n" : "Not overweight capacity.\n";
		cout << text;
	}
};

int main() {
	Car cars[3] = {
		Car("CB1706AC", "Octavia", 2015, "diesel", 6.2),
		Car("CB1234MT", "Superb", 2018, "diesel", 6.9),
		Car("CB4190PC", "Kodiaq", 2022, "petrol", 8.6),
	};

	Truck trucks[4] = {
		Truck("CA4533CX", "MAN", 2012, 10, 4),
		Truck("CB7751XA", "Volvo", 2017, 14, 8),
		Truck("CB4077TB", "Mercedes", 2019, 11, 12),
		Truck("CB0865", "Iveico", 2020, 3, 1),
	};

	Car* oldestCar = nullptr;
	int year = INT16_MAX;
	for (const auto& c : cars) {
		c.displayInfo();

		if (c.getYear() < year) {
			year = c.getYear();
			oldestCar = const_cast<Car*>(&c);
		}
	}

	cout << "Oldest car:\n";
	oldestCar->displayInfo();

	for (const auto& t : trucks) {
		t.displayInfo();
	}

	return 0;
}

// 08
#include <iostream>

using namespace std;

class Currency {
protected:
	int value;
	double course;
public:
	Currency(int v, double c) : value(v), course(c) {};

	int getValue() const { return value; }
	double getCourse() const { return course; }

	virtual double convertCurrency() const = 0;
};

class EuroToLev :public Currency {
public:
	EuroToLev(int v, double c) : Currency(v, c) {};

	double convertCurrency() const override {
		return getValue() * getCourse();
	}
};

class LevToEuro :public Currency {
public:
	LevToEuro(int v, double c) : Currency(v, c) {};

	double convertCurrency() const override {
		return getValue() * getCourse();
	}
};

int main() {
	EuroToLev etl(100, 1.96);
	cout << etl.getValue() << "E = " << etl.convertCurrency() << "L\n";

	LevToEuro lte(100, 0.51);
	cout << lte.getValue() << "L = " << lte.convertCurrency() << "E\n";

	return 0;
}

// 09
#include <iostream>

using namespace std;

class CurrencyConverter {
private:
	int value;
public:
	CurrencyConverter(int v) : value(v) {};

	int getValue() const { return value; }

	double convert(double course) const {
		return value * course;
	}

	void display() const {
		double course;
		cout << "Enter convert course: ";
		cin >> course;
		cout << "Before conversion: " << getValue() << endl;
		cout << "After conversion: " << convert(course) << endl;
	}
};

int main() {
	CurrencyConverter c1(75);
	c1.display();

	return 0;
}