/*
Задание:
Да се напише програма, която дефинира клас Appliance, описващ електроуред с атрибути за марка и модел. Освен това, 
да се дефинира производен клас WashingMachine на класа Appliance, който добавя характеристики като капацитет на 
барабана (в килограми) и наличие на функция за сушене. Да се дефинира обект от клас WashingMachine и да се изведе 
информацията за него. Също така, да се дефинира клас SmartWashingMachine, производен на класа WashingMachine, който 
реализира концепцията за интелигентна пералня с допълнителен параметър за свързаност с интернет (булева стойност). 
Ако пералнята има свързаност с интернет, тя може да бъде стартирана дистанционно. Реализирайте подходящи методи за 
работа със свойствата на класовете. Реализирайте задачата така, че методите на производните класове да не използват 
директно наследените член-данни от основните им класове. Инициализиращите действия трябва да се извършват чрез 
подходящи конструктори. Демонстрирайте работата на класовете с подходящи обекти.
*/

#include <iostream>
#include <string>

using namespace std;

class Appliance {
private:
	string brand;
	string model;
public:
	Appliance(string b, string m) {
		brand = b;
		model = m;
	}

	string getBrand() { return brand; }
	string getModel() { return model; }

	string info() {
		return "Appliance: " + getBrand() + ' ' + getModel() + '\n';
	}
};

class WashingMachine : public Appliance {
private:
	int capacity;
	bool hasDryFunc;
public:
	WashingMachine(string b, string m, int c, bool hdf) : Appliance(b, m) {
		capacity = c;
		hasDryFunc = hdf;
	}

	int getCapacity() { return capacity; }
	bool getHasDryFunction() { return hasDryFunc; }

	void dry() {
		if (getHasDryFunction()) {
			cout << "Drying laundry.\n";
			return;
		}

		cout << "Washing machine does not have dry functionallity.\n";
	}

	string info() {
		string sub = getHasDryFunction() ? ", has dry function.\n" : ", does not have dry function\n";
		return "Washing Machine: " + getBrand() + ' ' + getModel() + ", Capacity: " + to_string(getCapacity()) + sub;
	}
};

class SmartWashingMachine : public WashingMachine {
private:
	bool isConnected;
public:
	SmartWashingMachine(string b, string m, int c, bool hdf, bool ic) : WashingMachine(b, m, c, hdf) {
		isConnected = ic;
	}

	bool getIsConnected() { return isConnected; }

	void turnOn() {
		if (getIsConnected()) {
			cout << "Turned on via internet.\n";
			return;
		}

		cout << "Turned on manually.\n";
	}

	string info() {
		string sub = getHasDryFunction() ? ", has dry function" : ", does not have dry function";
		string sub2 = getIsConnected() ? " and is connected to Internet\n" : "and is not connected to Internet.\n";
		return "Washing Machine: " + getBrand() + ' ' + getModel() + ", Capacity: " + to_string(getCapacity()) + sub + sub2;
	}
};

int main() {
	Appliance i1("Some Brand", "Some Model");
	cout << i1.info();

	WashingMachine i2("Some Brand2", "Some Model2", 7, true);
	cout << i2.info();

	SmartWashingMachine i3("Some Brand3", "Some Model3", 8, false, true);
	cout << i3.info();
	i3.turnOn();

	return 0;
}