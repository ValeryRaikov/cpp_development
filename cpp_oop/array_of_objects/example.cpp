#include <iostream>

using namespace std;

class ProgrammingStudent;
class ArtStudent;
class MusicStudent;

class Student {
private:
    string name;
    int age;
    char gender;
public:
    string getName() { return name; }
    void setName(string newName) { name = newName; }
    int getAge() { return age; }
    void setAge(int newAge) { age = newAge; }
    char getGender() { return gender; }
    void setGender(char newGender) { gender = newGender; }

    virtual void study() = 0;

    friend class ProgrammingStudent;
    friend class ArtStudent;
    friend class MusicStudent;
};

class ProgrammingStudent: public Student {
public:
    ProgrammingStudent(string name, int age, char gender) {
        this->name = name;
        this->age = age;
        this->gender = gender;
    }

    void study() {
        cout << "Studing programming!" << endl;
    }
};

class ArtStudent: public Student {
public:
    ArtStudent(string name, int age, char gender) {
        this->name = name;
        this->age = age;
        this->gender = gender;
    }

    void study() {
        cout << "Studing arts!" << endl;
    }
};

class MusicStudent: public Student {
public:
    MusicStudent(string name, int age, char gender) {
        this->name = name;
        this->age = age;
        this->gender = gender;
    }

    void study() {
        cout << "Studing musics!" << endl;
    }
};

int main() {
    Student* students[3];
    students[0] = new ProgrammingStudent("Valery Raikov", 21, 'M');
    students[1] = new ArtStudent("Magdalena Philipova", 19, 'F');
    students[2] = new MusicStudent("Maria Peshova", 23, 'F');

    for (Student* student: students) {
        student->study();
    }

    for (Student* student: students) {
        delete student;
    }

    return 0;
}