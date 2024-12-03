/*
Задание:
Да се напише програма, която дефинира клас Vehicle, определящ превозно средство чрез марка и регистрационен номер. 
Освен това, да се дефинира производен клас Car на класа Vehicle, който описва понятието автомобил с допълнителни 
характеристики като брой врати и тип гориво. Да се дефинира обект от клас Car и да се изведе информацията за него.
Също така, да се дефинира клас ElectricCar, производен на класа Car, който реализира понятието електрически автомобил 
с допълнителен параметър за капацитет на батерията (в kWh). Електромобилът може да бъде зареден, само ако капацитетът 
на батерията му е под 80%. Реализирайте подходящи методи за работа със свойствата на класовете.Реализирайте задачата 
така, че методите на производните класове да използват директно наследените член-данни от основните им класове. 
Инициализиращите действия трябва да се извършват чрез подходящи конструктори. Демонстрирайте работата на класовете 
с подходящи обекти.
*/

#include <iostream>

using namespace std;

class Vehicle {
protected:
	string brand;
	string regNum;
public:
	Vehicle(string brand, string regNum) {
		this->brand = brand;
		this->regNum = regNum;
	}

	string getBrand() { return brand; }
	string getRegNum() { return regNum; }

	void display() {
		cout << "Vehicle:\n";
		cout << getBrand() << " - " << getRegNum() << endl;
	}
};

class Car : public Vehicle {
protected:
	int doorNum;
	string fuelType;
public:
	Car(string brand, string regNum, int doorNum, string fuelType) : Vehicle(brand, regNum) {
		this->doorNum = doorNum;
		this->fuelType = fuelType;
	}

	int getDoorNum() { return doorNum; }
	string getFuelType() { return fuelType; }

	void display() {
		cout << "Car:\n";
		cout << getBrand() << " - " << getRegNum() << " - " << getDoorNum() << " - " << getFuelType() << endl;
	}
};

class ElectricCar : public Car {
protected:
	int bCapacity;
public:
	ElectricCar(string brand, string regNum, int doorNum, string fuelType, int bCapacity)
		: Car(brand, regNum, doorNum, fuelType) {
		this->bCapacity = bCapacity;
	}

	int getBCapacity() { return bCapacity; }

	void recharge() {
		if (getBCapacity() >= 80) {
			cout << "Electric car cannot be recharged! Batery capacity is " << getBCapacity() << endl;
			return;
		}

		cout << "Recharging electric car...\n";
		bCapacity = 100;
	}

	void display() {
		cout << "Electric Car:\n";
		cout << getBrand() << " - " << getRegNum() << " - " << getDoorNum() << " - " << getFuelType() << " - "
			 << getBCapacity() << endl;
	}
};

int main() {
	Vehicle v1("BMW", "CB1234MT");
	v1.display();
	cout << endl;

	Car c1("Skoda", "CB1706AC", 5, "diesel");
	c1.display();
	cout << endl;

	ElectricCar ec1("Toyota", "EA5574BC", 5, "electricity", 60);
	ec1.display();
	ec1.recharge();
	ec1.display();

	return 0;
}