#include <iostream>

int main() {
    using namespace std;

    string cars[] = {"Volvo", "VW", "Skoda", "Mercedes", "Subaru"};
    int grades[] = {75, 89, 61, 68, 78}; 

    for (string car: cars) {
        cout << car << '\n'; 
    }

    for (int grade: grades) {
        cout << "Grade is: " << grade << '\n';
    }

    return 0;
}