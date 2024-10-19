#include <iostream>

using namespace std;

int main() {
    int *p_num = NULL;

    p_num = new int;

    *p_num = 21;

    cout << "Address: " << p_num << '\n';
    cout << "Value: " << *p_num << '\n';

    delete p_num; // avoid memory leak

    char *p_grades = NULL;

    int size;
    cout << "Enter grade number: ";
    cin >> size;
    p_grades = new char[size];

    for (int i = 0; i < size; ++i) {
        cout << "Enter grade #" << i + 1 << '\n';
        cin >> p_grades + i;
    }

    for (int i = 0; i < size; ++i) {
        cout << "Grade: " << p_grades[i] << '\n';
    }

    delete p_grades;

    return 0;
}