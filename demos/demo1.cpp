#include <iostream>
#include <list>

using namespace std;

class UniversityStudent;

class Student {
private:
    string name;
    int age;
    string egn;
    list<string> subjects;
public:
    Student(string name, int age, string egn) {
        this->name = name;
        this->age = age;
        this->egn = egn;
        this->subjects = {};
    }

    string getName() {
        return this->name;
    }

    void setName(string value) {
        this->name = value;
    }

    int getAge() {
        return this->age;
    }

    void setAge(int value) {
        this->age = value;
    }

    string getEgn() {
        return this->egn;
    }

    void setEgn(string value) {
        this->egn = value;
    }

    list<string> getSubjects() {
        return this->subjects;
    }

    void addSubject(string subject) {
        this->subjects.push_back(subject);
    }

    void clearSubjects() {
        this->subjects.clear();
    }

    void printInfo() {
        cout << "Student information:\n";
        cout << "Name: " << getName() << endl;
        cout << "Age: " << getAge() << endl;
        cout << "EGN: " << getEgn() << endl;
        if (getSubjects().empty()) {
            cout << "No subjects added for this student!\n";
        } else {
            cout << "Subjects:\n";
            for (string subject: getSubjects()) {
                cout << "-> " << subject << endl;
            }
        }
    }

    friend class UniversityStudent;
};

class SchoolStudent: public Student {
private:
    int schoolYear;
public:
    SchoolStudent(string name, int age, string egn, int schoolYear): 
    Student(name, age, egn), schoolYear(schoolYear) {}

    int getSchoolYear() {
        return this->schoolYear;
    }

    void setSchoolYear(int value) {
        this->schoolYear = value;
    }

    void printInfo() {
        cout << "Student information:\n";
        cout << "Name: " << getName() << endl;
        cout << "Age: " << getAge() << endl;
        cout << "EGN: " << getEgn() << endl;
        cout << "Year: " << getSchoolYear() << endl;
        if (getSubjects().empty()) {
            cout << "No subjects added for this student!\n";
        } else {
            cout << "Subjects:\n";
            for (string subject: getSubjects()) {
                cout << "-> " << subject << endl;
            }
        }
    }
};

class UniversityStudent: public Student {
private:
    string facultyName;
    string specialtyName;
    list<int> grades;
public:
    UniversityStudent(string name, int age, string egn, string facultyName, string specialtyName, list<int> grades)
    : Student(name, age, egn), facultyName(facultyName), specialtyName(specialtyName), grades({}) {}

    string getFacultyName() {
        return this->facultyName;
    }

    void setFacultyName(string value) {
        this->facultyName = value;
    }

    string getSpecialtyName() {
        return this->specialtyName;
    }

    void setSpecialtyName(string value) {
        this->specialtyName = value;
    }

    list<int> getGrades() {
        return this->grades;
    }

    static UniversityStudent initializeStudent() {
        string name, egn, facultyName, specialtyName;
        int age;
        list<int> grades;

        cout << "Enter name: ";
        getline(cin >> ws, name);
        cout << "Enter age: ";
        cin >> age;
        cout << "Enter EGN: ";
        cin >> egn;
        cin.ignore();
        
        cout << "Enter faculty name: ";
        getline(cin, facultyName);
        cout << "Enter specialty name: ";
        getline(cin, specialtyName);

        int gradesCount;
        cout << "Enter number of grades: ";
        cin >> gradesCount;

        for (int i = 0; i < gradesCount; ++i) {
            int grade;
            cout << "Enter grade #" << i + 1 << ": ";
            cin >> grade;
            grades.push_back(grade);
        }

        return UniversityStudent(name, age, egn, facultyName, specialtyName, grades);
    }

    void addGrade(int grade) {
        this->grades.push_back(grade);
    }

    void printInfo() {
        cout << "Student information:\n";
        cout << "Name: " << getName() << endl;
        cout << "Age: " << getAge() << endl;
        cout << "EGN: " << getEgn() << endl;
        cout << "Faculty: " << getFacultyName() << endl;
        cout << "Specialty: " << getSpecialtyName() << endl;
        if (getSubjects().empty()) {
            cout << "No subjects added for this student!\n";
        } else {
            cout << "Subjects:\n";
            for (string subject: getSubjects()) {
                cout << "-> " << subject << endl;
            }
        }
        if (getGrades().empty()) {
            cout << "No grades added for this student!\n";
        } else {
            cout << "Grades:\n";
            for (int grade: getGrades()) {
                cout << "-> " << grade << endl;
            }
        }
    }
};

int main() {
    Student st = Student("Ivaylo Petkov", 14, "1020304050");
    st.addSubject("Geography");
    st.addSubject("History");
    st.clearSubjects();
    st.printInfo();

    cout << endl;

    SchoolStudent sst = SchoolStudent("Valery", 21, "0346126486", 9);
    sst.printInfo();

    sst.addSubject("Mathematics");
    sst.addSubject("Programming");

    sst.printInfo();

    cout << endl;

    UniversityStudent ust = UniversityStudent::initializeStudent();
    ust.addGrade(5);

    ust.printInfo();

    return 0;
}