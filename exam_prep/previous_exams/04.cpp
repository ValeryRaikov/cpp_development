#include <iostream>

using namespace std;

class Vehicle {
protected:
	char brand;
	int year;
public:
	Vehicle(char b, int y) {
		brand = b;
		year = y;
	}

	char getBrand() const { return brand; }
	void setBrand(char value) { brand = value; }
	int getYear() const { return year; }
	void setYear(int value) { year = value; }

	void display() const {
		cout << "Vehicle: " << getBrand() << " of year: " << getYear() << endl;
	}

};

class Automobile : public Vehicle {
protected:
	string regNum;
public:
	Automobile(char b, int y, string rn) : Vehicle(b, y) {
		regNum = rn;
	}

	string getRegNum() const { return regNum; }
	void setRegNum(string value) { regNum = value; }

	void display() const {
		cout << "Automobile: " << getBrand() << " of year: " << getYear() << " with registration: " << getRegNum() << endl;
	}
};

class LoanedAutomobile : public Automobile {
protected:
	int price;
public:
	LoanedAutomobile(char b, int y, string rn, int p) : Automobile(b, y, rn) {
		price = p;
	}

	int getPrice() const { return price; }
	void setPrice(int value) { price = value; }

	void display() const {
		cout << "Loaned Automobile: " << getBrand() << " of year: " << getYear() << " with registration: " << getRegNum()
			<< " and price for loan: " << getPrice() << endl;
	}
};

int main() {
	Vehicle v('S', 2015);
	v.display();

	Automobile a('M', 2022, "CB1706AC");
	a.display();

	LoanedAutomobile la('P', 2020, "CB1234BC", 100);
	la.display();

	return 0;
}