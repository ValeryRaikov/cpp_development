#include <iostream>

#include "subjects.cpp"

using namespace std;

class Teacher {
private:
    string firstName;
    string lastName;
    int age;
    char gender;
protected:
    int yearOfExperience;
    subjects specialization;
public:
    Teacher(string firstName, string lastName, int age, char gender, int yearOfExperience, subjects specialization) {
        this->firstName = firstName;
        this->lastName = lastName;
        this->age = age;
        this->gender = gender;
        this->yearOfExperience = yearOfExperience;
        this->specialization = specialization;
    }

    string getFirstName() { return firstName; }
    void setFirstName(string value) { if (!value.empty()) { firstName = value; } }

    string getLastName() { return lastName; }
    void setLastName(string value) { if (!value.empty()) { lastName = value; } }

    int getAge() { return age; }
    void setAge(int value) { if (value > 0 && value < 20) { age = value; } }

    char getGender() { return gender; }
    void setGender(char value) { if (value == 'm' || value == 'f') { gender = value; } }

    int getYearOfExperience() { return yearOfExperience; }
    void setYearOfExperience(int value) { if (value > 0) { yearOfExperience = value; } }

    subjects getSpecialization() { return specialization; }
    void setSpecialization(subjects value) { if (value > BULGARIAN_LANGUAGE && value < SPORT) { specialization = value; } }

    static Teacher createTeacher() {
        string firstName, lastName;
        int age, yearOfExperience;
        char gender;
        int specializationInput;

        cout << "*** Teacher Registration ***\n";

        cout << "Enter teacher first name: ";
        getline(cin, firstName);

        cout << "Enter teacher last name: ";
        getline(cin, lastName);

        cout << "Enter teacher age: ";
        cin >> age;

        cout << "Enter teacher gender: ";
        cin >> gender;

        cout << "Enter year of experience: ";
        cin >> yearOfExperience;

        cout << "Enter teacher specialization (0: BULGARIAN_LANGUAGE, 1: ENGLISH_LANGUAGE, 2: MATHEMATICS, 3: INFORMATION_TECHNOLOGIES, 4: SPORT): ";
        cin >> specializationInput;

        if (!firstName.empty() && !lastName.empty() && age > 0 && age < 20 && gender == 'm' || gender == 'f'
        && yearOfExperience > 0 && specializationInput > BULGARIAN_LANGUAGE && specializationInput < SPORT) {
            cout << "Teacher registered successfully!\n";
            return Teacher(firstName, lastName, age, gender, yearOfExperience, specialization);
        }

        cout << "Failed to register teacher!\n";
        exit(1);
    }

    friend ostream& operator<<(ostream& os, const Teacher& teacher) {
        os << "*** Teacher Info ***\n";
        os << "First Name: " << teacher.firstName << "\n";
        os << "Last Name: " << teacher.lastName << "\n";
        os << "Age: " << teacher.age << "\n";
        os << "Gender: " << teacher.gender << "\n";
        os << "Year of experience: " << teacher.yearOfExperience << "\n";
        os << "Specialization: ";

        switch (teacher.specialization) {
            case BULGARIAN_LANGUAGE: os << "Bulgarian Language"; break;
            case ENGLISH_LANGUAGE: os << "English Language"; break;
            case MATHEMATICS: os << "Mathematics"; break;
            case INFORMATION_TECHNOLOGIES: os << "Information Technologies"; break;
            case SPORT: os << "Sport"; break;
        }
        os << "\n";

        return os;
    }
};