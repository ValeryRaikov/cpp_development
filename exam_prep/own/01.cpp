#include <iostream>
#include <memory>
#include <string>
#include <vector>

using namespace std;

class ComputerBase {
public:
	virtual ~ComputerBase() = default;
	virtual void display() const = 0; 
};

class Computer : public ComputerBase {
private:
	string brand;
	string model;
	int year;
public:
	Computer(string brand, string model, int year) : brand(brand), model(model), year(year) {};

	string getBrand() const { return brand; }
	string getModel() const { return model; }
	int getYear() const { return year; }

	void display() const override {
		cout << "Computer:\n";
		cout << "Brand: " << getBrand() << "\nModel: " << getModel() << "\nYear: " << getYear() << endl;
	}
};

class ProgrammingComputer : public Computer {
private:
	string processor;
	int memory;
public:
	ProgrammingComputer(string brand, string model, int year, string processor, int memory) : Computer(brand, model, year),
		processor(processor), memory(memory) {};

	string getProcessor() const { return processor; }
	int getMemory() const { return memory; }

	bool hasEnoughMemory() {
		return getMemory() > 256;
	}

	void display() const override {
		cout << "Programming computer:\n";
		cout << "Brand: " << getBrand() << "\nModel: " << getModel() << "\nYear: " << getYear()
			<< "\nProcessor: " << getProcessor() << "\nMemory: " << getMemory() << endl;
	}
};

class Student {
private:
	string fullName;
	int age;
	unique_ptr<ComputerBase> computer;
public:
	Student(string fullName, int age, unique_ptr<ComputerBase> computer) : fullName(fullName), age(age), 
		computer(move(computer)) {};

	Student(Student&& other) noexcept    // Move constructor
		: fullName(move(other.fullName)), age(other.age), computer(move(other.computer)) {}

	Student(const Student&) = delete;

	string getFullName() const { return fullName; }
	int getAge() const { return age; }

	void displayComputer() const {
		computer->display();
	}

	friend ostream& operator<<(ostream& os, const Student& st) {
		os << "Student:\n";
		os << "Name: " << st.getFullName() << " - " << st.getAge() << endl;

		return os;
	}
};

int main() {
	auto comp1 = make_unique<Computer>("Dell", "XPS", 2021);
	auto comp2 = make_unique<ProgrammingComputer>("Apple", "MacBook Pro", 2022, "M1", 512);
	auto comp3 = make_unique<ProgrammingComputer>("Acer", "Predator", 2023, "Intel Core i9", 1024);

	Student student1("Alice", 20, move(comp1));
	Student student2("Bob", 22, move(comp2));
	Student student3("Valery", 21, move(comp3));

	vector<Student> students;
	students.emplace_back("Alice", 20, move(comp1));
	students.emplace_back("Bob", 22, move(comp2));
	students.emplace_back("Valery", 21, move(comp3));

	for (const auto& student : students) {
		cout << student;
		student.displayComputer();
		cout << endl;
	}

	return 0;
}