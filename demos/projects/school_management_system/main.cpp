#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include "subjects.cpp"
#include "school.cpp"
#include "student.cpp"
#include "teacher.cpp"

using namespace std;

int main() {
    vector<School> schools;
    vector<Student> students;
    vector<Teacher> teachers;

    int choice;

    cout << "*** School Management System Menu ***\n";
    do {
        cout << "\nEnter your choice to access a specific menu\n";
        cout << "(1 - School menu, 2 - Student menu, 3 - Teacher menu, 4 - EXIT): ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            int command;
            case 1:
                cout << "*** School Menu ***\n";
                cout << "Enter command:\n";
                cout << "1 - Create school\n";
                cout << "2 - Add student to class\n";
                cout << "3 - Add teacher to subject\n";
                cout << "4 - Exclude student from school\n";
                cin >> command;
                cin.ignore();

                switch (command) {
                    case 1: {
                        School school = School::createSchool();
                        schools.push_back(school);
                        break;
                    }
                    case 2: {
                        if (schools.empty() || students.empty()) {
                            cout << "No schools or students added yet!\n";
                            break;
                        }

                        string schoolName, studentEgn;
                        int year;

                        cout << "Enter school name: ";
                        getline(cin, schoolName);

                        cout << "Enter student EGN: ";
                        getline(cin, studentEgn);

                        cout << "Enter student class year: ";
                        cin >> year;
                        cin.ignore();

                        auto schoolIt = find_if(schools.begin(), schools.end(), [&](const School& sc) {
                            return sc.getName() == schoolName;
                        });

                        if (schoolIt != schools.end()) {
                            auto studentIt = find_if(students.begin(), students.end(), [&](const Student& st) {
                                return st.getEgn() == studentEgn;
                            });

                            if (studentIt != students.end()) {
                                schoolIt->addStudentToClass(*studentIt, year);
                                cout << "Added student with EGN " << studentEgn << " to class " << year << ".\n";
                            } else {
                                cout << "No student found with EGN " << studentEgn << ".\n";
                            }
                        } else {
                            cout << "No school found with the name " << schoolName << ".\n";
                        }
                        break;
                    }
                    case 3: {
                        if (schools.empty() || teachers.empty()) {
                            cout << "No schools or teachers added yet!\n";
                            break;
                        }

                        string schoolName, teacherName;
                        int subjectInput;

                        cout << "Enter school name: ";
                        getline(cin, schoolName);

                        cout << "Enter teacher name: ";
                        getline(cin, teacherName);

                        cout << "Enter subject (0: BULGARIAN_LANGUAGE, 1: ENGLISH_LANGUAGE, etc.): ";
                        cin >> subjectInput;
                        cin.ignore();

                        subjects subject = static_cast<subjects>(subjectInput);

                        auto schoolIt = find_if(schools.begin(), schools.end(), [&](const School& sc) {
                            return sc.getName() == schoolName;
                        });

                        if (schoolIt != schools.end()) {
                            auto teacherIt = find_if(teachers.begin(), teachers.end(), [&](const Teacher& t) {
                                return t.getFirstName() + " " + t.getLastName() == teacherName;
                            });

                            if (teacherIt != teachers.end()) {
                                schoolIt->addTeacherToSubject(*teacherIt, subject);
                                cout << "Added teacher " << teacherName << " to subject.\n";
                            } else {
                                cout << "No teacher found with the name " << teacherName << ".\n";
                            }
                        } else {
                            cout << "No school found with the name " << schoolName << ".\n";
                        }
                        break;
                    }
                    case 4: {
                        if (schools.empty() || students.empty()) {
                            cout << "No schools or students added yet!\n";
                            break;
                        }

                        string schoolName, studentEgn;

                        cout << "Enter school name: ";
                        getline(cin, schoolName);

                        cout << "Enter student EGN: ";
                        getline(cin, studentEgn);

                        auto schoolIt = find_if(schools.begin(), schools.end(), [&](const School& sc) {
                            return sc.getName() == schoolName;
                        });

                        if (schoolIt != schools.end()) {
                            auto studentIt = find_if(students.begin(), students.end(), [&](const Student& st) {
                                return st.getEgn() == studentEgn;
                            });

                            if (studentIt != students.end()) {
                                schoolIt->excludeStudentFromClass(*studentIt);
                                cout << "Removed student with EGN " << studentEgn << " from school " << schoolName << ".\n";
                            } else {
                                cout << "No student found with EGN " << studentEgn << ".\n";
                            }
                        } else {
                            cout << "No school found with the name " << schoolName << ".\n";
                        }
                        break;
                    }
                    default:
                        cout << "Invalid command!\n";
                        break;
                }
                break;

            case 2:
                cout << "*** Student Menu ***\n";
                // TODO Implement student-related menu
                break;

            case 3:
                cout << "*** Teacher Menu ***\n";
                // TODO Implement teacher-related menu
                break;

            case 4:
                cout << "Exiting the program...\n";
                break;

            default:
                cout << "Invalid choice!\n";
                break;
        }
    } while (choice != 4);

    cout << "Goodbye!\n";
    return 0;
}