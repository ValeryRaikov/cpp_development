#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

#include "student.cpp"
#include "teacher.cpp"

using namespace std;

class School {
private:
    string name;
    map<int, vector<Student>> students;
    map<subjects, vector<Teacher>> teachers;
public:
    School (string name) {
        this->name = name;

        for (int i = 1; i <= 12; i++) {
            students[i] = vector<Student>();
        }

        for (int i = BULGARIAN_LANGUAGE; i <= SPORT; i++) {
            teachers[static_cast<subjects>(i)] = vector<Teacher>();
        }
    }

    string getName() { return name; }
    void setName(string value) { if (!value.empty()) { name = value; } }

    static School createSchool() {
        string name;

        cout << "*** School Creation ***\n";
        getline(cin, name);

        if (!name.empty()) {
            cout << "School created successfully!\n";
            return School(name);
        }

        cout << "Failed to create school!\n";
        exit(1);
    }

    void addStudentToClass(Student student, int classYear) {
        if (classYear < 1 || classYear > 12) {
            cout << "Invalid class year! Please provide a value between 1 and 12.\n";
            return;
        }

        for (const auto& existingStudent : students[classYear]) {
            if (existingStudent.getEgn() == student.getEgn()) {
                cout << "Student with EGN " << student.getEgn() << " is already in class " << classYear << ".\n";
                return;
            }
        }

        students[classYear].push_back(student);
        cout << "Student added to class year " << classYear << " successfully!\n";
    }

    void addTeacherToSubject(Teacher teacher, subjects subject) {
        if (subject < BULGARIAN_LANGUAGE || subject > SPORT) {
            cout << "Invalid subject!" << endl;
            return;
        }

        for (const auto& existingTeacher : teachers[subject]) {
            if (existingTeacher.getFirstName() == teacher.getFirstName() &&
                existingTeacher.getLastName() == teacher.getLastName() &&
                existingTeacher.getSpecialization() == teacher.getSpecialization()) {
                cout << "Teacher " << teacher.getFirstName() << " " << teacher.getLastName()
                    << " is already assigned to subject " << subject << "." << endl;
                return;
            }
        }

        teachers[subject].push_back(teacher);
        cout << "Teacher added to subject " << subject << " successfully!\n";
    }

    void excludeStudentFromClass(Student student) {
        for (auto& record : students) {
            auto& studentList = record.second;
            auto it = remove_if(studentList.begin(), studentList.end(),
                [&student](const Student& s) {
                    return s.getEgn() == student.getEgn();
                });

            if (it != studentList.end()) {
                studentList.erase(it, studentList.end());
                cout << "Student removed successfully from class " << record.first << "!\n";
                return;
            }
        }

        cout << "Student not found in the school database!\n";
    }

    friend ostream& operator<<(ostream& os, const School& school) {
        os << "*** School Info ***\n";
        os << "School name: " << school.name << "\n";

        os << "\nSchool Classes:\n";
        for (const auto& record : school.students) {
            os << "Class: " << record.first << "\n";
            for (const auto& student : record.second) {
                os << student << ", ";
            }
            os << "\n";
        }

        os << "\nSchool teachers:\n";
        for (const auto& record : school.teachers) {
            os << "Subject: " << record.first << "\n";
            for (const auto& teacher : record.second) {
                os << teacher << ", ";
            }
            os << "\n";
        }

        return os;
    }

    ~School() {
        delete students;
        students = NULL;
        delete teachers;
        teachers = NULL;
    }
};