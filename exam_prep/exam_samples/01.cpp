/*
Зад.: Да се напише програма, която дефинира клас People, определящ човек по име
и единен граждански номер (ЕГН), а също производен клас Student на класа People,
който определя понятието студент като човек, който има факултетен номер и среден
успех. Да се дефинира обект от клас Student и се изведе дефинираният обект. Да се
дефинира клас PStudent, производен на класа Student, реализиращ понятието студент от
платена форма на обучение. Студентът може да получава стипендия само ако средния
успех му е много добър (над 4.5). Реализирайте подходящи методи за получаване на
стойностите на променливите. Реализирайте задачата така, че методите на
производните класове да могат пряко да използват наследените член-данни на
основните им класове. Инициализиращите действия да се изпълняват от подходящи
конструктори. Демонстрирайте работата на класовете с подходящи обекти.
*/

#include <iostream>

using namespace std;

class People {
protected:
    string name;
    string egn;
public:
    People(string name, string egn) {
        this->name = name;
        this->egn = egn;
    }

    string getName() { return name; }
    void setName(string value) { name = value; }
    string getEgn() { return egn; }
    void setEgn(string value) { egn = value; }
};

class Student : public People {
protected:
    string facultyNumber;
    double averageGrade;
public:
    Student(string name, string egn, string facultyNumber, double averageGrade) : People(name, egn) {
        this->facultyNumber = facultyNumber;
        this->averageGrade = averageGrade;
    }

    string getFacultyNumber() { return facultyNumber; }
    void setFacultyNumber(string value) { facultyNumber = value; }
    double getAverageGrade() { return averageGrade; }
    void setAverageGrade(double value) { averageGrade = value; }

    friend ostream& operator<<(ostream& os, const Student& student) {
        os << student.name << " - " << student.egn << " - " << student.facultyNumber
            << " - " << student.averageGrade << endl;

        return os;
    }
};

class PStudent : public Student {
public:
    PStudent(string name, string egn, string facultyNumber, double averageGrade) :
        Student(name, egn, facultyNumber, averageGrade) {};

    void payForm() {
        if (getAverageGrade() > 4.5) {
            cout << "Student receives payment!\n";
            return;
        }

        cout << "Student does not receive payment!\n";
    }
};

int main() {
    People p1("Maria Popova", "0123456789");
    cout << "Name: " << p1.getName() << endl;
    cout << "EGN: " << p1.getEgn() << endl;
    cout << endl;

    Student s1("Valery Raikov", "9876543210", "121222139", 5.55);
    cout << s1;
    cout << endl;

    PStudent ps1("Ivan Motovski", "1122334455", "321456987", 4.98);
    cout << "Name: " << ps1.getName() << endl;
    cout << "EGN: " << ps1.getEgn() << endl;
    cout << "Faculty Number: " << ps1.getFacultyNumber() << endl;
    cout << "Average Grade: " << ps1.getAverageGrade() << endl;
    ps1.payForm();
    cout << endl;

    return 0;
}