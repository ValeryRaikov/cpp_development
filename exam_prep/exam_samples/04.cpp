/*
Да се напише програма, която дефинира клас Person, описващ човек с име, единен граждански номер (ЕГН), и възраст. 
Създайте производен клас Employee, който добавя информация за служител като човек, който има номер на служител и заплата. 
Да се дефинира обект от клас Employee и да се изведе информацията за него. Да се дефинира клас Manager, производен на 
класа Employee, който допълнително определя понятието ръководител с информация за отдела, който ръководи, и допълнителен 
бонус към заплатата. Ръководителят може да получи бонус само ако заплатата му е над 2000 лева. Реализирайте подходящи 
методи за извличане и задаване на стойностите на променливите. Методите на производните класове трябва директно да 
използват наследените член-данни на основните класове. Инициализиращите действия да се изпълняват от подходящи 
конструктори. Демонстрирайте работата на класовете чрез подходящи обекти.
*/

#include <iostream>

using namespace std;

class Person {
protected:
	string name;
	string egn;
	int age;
public:
	Person(string n, string e, int a) {
		setName(n);
		setEgn(e);
		setAge(a);
	};

	string getName() { return name; }
	void setName(string value) { name = value; }
	string getEgn() { return egn; }
	void setEgn(string value) { egn = value; }
	int getAge() { return age; }
	void setAge(int value) { age = value; }
};

class Employee : public Person {
protected:
	int employeeNum;
	int salary;
public:
	Employee(string n, string e, int a, int en, int s) : Person(n, e, a) {
		setEmployeeNum(en);
		setSalary(s);
	};

	int getEmployeeNum() { return employeeNum; }
	void setEmployeeNum(int value) { employeeNum = value; }
	int getSalary() { return salary; }
	void setSalary(int value) { salary = value; }
};

class Manager : public Employee {
protected:
	int departmentId;
	int bonus;
public:
	Manager(string n, string e, int a, int en, int s, int d, int b) : Employee(n, e, a, en, s) {
		setDepartmentId(d);
		setBonus(b);
	};

	int getDepartmentId() { return departmentId; }
	void setDepartmentId(int value) { departmentId = value; }
	int getBonus() { return bonus; }
	void setBonus(int value) {
		if (getSalary() > 2000) {
			bonus = value;
		} else {
			bonus = 0;
		}
	}
};

int main() {
	Person p("Valery", "0346126587", 21);
	cout << "Person:\n";
	cout << "Name: " << p.getName() << ", EGN: " << p.getEgn() << ", Age: " << p.getAge() << endl;
	cout << endl;

	Employee e("Ivaylo", "9448206470", 30, 101, 2500);
	cout << "Employee:\n";
	cout << "Name: " << e.getName() << ", EGN: " << e.getEgn() << ", Age: " << e.getAge() << ", Employee N: "
		<< e.getEmployeeNum() << ", Salary: " << e.getSalary() << endl;
	cout << endl;

	Manager m("Peter Petrov", "7850246868", 46, 102, 5000, 1, 250);
	cout << "Manager:\n";
	cout << "Name: " << m.getName() << ", EGN: " << m.getEgn() << ", Age: " << m.getAge() << ", Employee N: "
		<< m.getEmployeeNum() << ", Salary: " << m.getSalary() << ", Department Id: " << m.getDepartmentId()
		<< ", Bonus: " << m.getBonus() << endl;

	return 0;
}