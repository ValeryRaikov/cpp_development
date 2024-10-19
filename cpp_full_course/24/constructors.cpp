#include <iostream>

using namespace std;

class Student {
    public:
        string name;
        int age;
        string specialty;
        double average;

    Student(string name, int age, string specialty, double average) {
        this->name = name;
        this->age = age;
        this->specialty = specialty;
        this->average = average;
    }
};

int main() {
    Student student1("Valery", 21, "Software Engineering", 5.55);
    Student student2("Magdalena", 19, "Artist Engineering", 5.4);

    cout << student1.name << '\n' << student1.age << '\n' 
        << student1.specialty << '\n' << student1.average << '\n';

    return 0;
}