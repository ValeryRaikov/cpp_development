#include <iostream>

using namespace std;

struct student {
    string name;
    double gpa;
    bool enrolled;
};

int main() {
    student student_obj;
    student_obj.name = "Valery";
    student_obj.gpa = 4.5;
    student_obj.enrolled = true;

    cout << student_obj.name << ", " << student_obj.gpa << ", " << student_obj.enrolled << endl;

    return 0;
}