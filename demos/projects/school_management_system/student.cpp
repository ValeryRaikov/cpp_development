#include <iostream>
#include <map>
#include <vector>

#include "grades.cpp"
#include "subjects.cpp"

using namespace std;

class Student {
private:
    string firstName;
    string lastName;
    string egn;
protected:
    int age;
    int year;
    map<subjects, vector<grades>> gradeRecords;
public:
    Student(string firstName, string lastName, string egn, int age, int year) {
        this->firstName = firstName;
        this->lastName = lastName;
        this->egn = egn;
        this->age = age;
        this->year = year;

        for (int i = BULGARIAN_LANGUAGE; i <= SPORT; i++) {
            gradeRecords[static_cast<subjects>(i)] = vector<grades>();
        }
    }

    string getFirstName() { return firstName; }
    void setFirstName(string value) { if (!value.empty()) { firstName = value; } }

    string getLastName() { return lastName; }
    void setLastName(string value) { if (!value.empty()) { lastName = value; } }

    string getEgn() { return egn; }
    void setEgn(string value) { if (!value.empty()) { egn = value; } }

    int getAge() { return age; }
    void setAge(int value) { if (value > 0 && value < 20) { age = value; } }

    int getYear() { return year; }
    void setYear(int value) { if (value > 0 && value < 13) { year = value; } }

    map<subjects, vector<grades>> getGradeRecords() { return gradeRecords; }

    static Student createStudent() {
        string firstName, lastName, egn; 
        int age, year;

        cout << "*** Student Registration ***\n";

        cout << "Enter student first name: ";
        getline(cin, firstName);

        cout << "Enter student last name: ";
        getline(cin, lastName);

        cout << "Enter student egn: ";
        getline(cin, egn);

        cout << "Enter student age: ";
        cin >> age;

        cout << "Enter school year class: ";
        cin >> year;

        if (!firstName.empty() && !lastName.empty() && !egn.empty() && age > 0 && age < 20 && year > 0 && year < 13) {
            cout << "Student registered successfully!\n";
            return Student(firstName, lastName, egn, age, year);
        }

        cout << "Failed to register student!\n";
        exit(1);
    }

    void addStudentGrade() {
        int subjectInput;
        int gradeInput;

        cout << "Enter subject (0: BULGARIAN_LANGUAGE, 1: ENGLISH_LANGUAGE, 2: MATHEMATICS, 3: INFORMATION_TECHNOLOGIES, 4: SPORT): ";
        cin >> subjectInput;  

        if (subjectInput < BULGARIAN_LANGUAGE || subjectInput > SPORT) {
            cout << "Invalid subject!" << endl;
            return;
        }

        subjects subject = static_cast<subjects>(subjectInput); 

        cout << "Enter grade for " << subject << " (0: A, 1: B, 2: C, 3: D, 4: F): ";
        cin >> gradeInput;

        if (gradeInput < A || gradeInput > F) {
            cout << "Invalid grade!" << endl;
            return;
        }

        grades grade = static_cast<grades>(gradeInput);

        gradeRecords[subject].push_back(grade);

        cout << "Grade added successfully!" << endl;
    }

    void calculateSubjectAvgGrade() {
        int subjectInput;

        int total = 0;
        double average = 0;

        cout << "Enter subject (0: BULGARIAN_LANGUAGE, 1: ENGLISH_LANGUAGE, 2: MATHEMATICS, 3: INFORMATION_TECHNOLOGIES, 4: SPORT): ";
        cin >> subjectInput;  

        if (subjectInput < BULGARIAN_LANGUAGE || subjectInput > SPORT) {
            cout << "Invalid subject!" << endl;
            return;
        }

        subjects subject = static_cast<subjects>(subjectInput); 

        if (gradeRecords[subject].size() == 0) {
            cout << "No grades available to calculate average for " << subject << endl;
            return;
        }

        for (const auto& grade : gradeRecords[subject]) {
            switch (grade) {
                case F: total += 6; break;
                case D: total += 5; break;
                case C: total += 4; break;
                case B: total += 3; break;
                case A: total += 2; break;
            }
        }

        average = static_cast<double>(total) / gradeRecords[subject].size();

        cout << "Subject average grade for " << subject << " is: " << average << endl;
    }

    void calculateAvgGrade() {
        int total = 0;
        int grades = 0;
        double average = 0;

        for (const auto& record : gradeRecords) {
            for (const auto& grade : record.second) {
                grades++;

                switch (grade) {
                    case F: total += 6; break;
                    case D: total += 5; break;
                    case C: total += 4; break;
                    case B: total += 3; break;
                    case A: total += 2; break;
                }
            }
        }

        if (grades > 0) {
            average = static_cast<double>(total) / grades;
            cout << "Student's average grade is: " << average << endl;
        } else {
            cout << "No grades available to calculate average." << endl;
        }
    }

    friend ostream& operator<<(ostream& os, const Student& student) {
        os << "*** Student Info ***\n";
        os << "First Name: " << student.firstName << "\n";
        os << "Last Name: " << student.lastName << "\n";
        os << "EGN: " << student.egn << "\n";
        os << "Age: " << student.age << "\n";
        os << "Year: " << student.year << "\n";

        os << "\nGrade Records:\n";
        for (const auto& record : student.gradeRecords) {
            os << "Subject: " << record.first << " | Grades: ";
            for (const auto& grade : record.second) {
                os << grade << ", ";
            }
            os << "\n";
        }

        return os;
    }

    ~Student() {
        delete gradeRecords;
        gradeRecords = NULL;
    }
};