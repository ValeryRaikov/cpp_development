#include <iostream>

#include "patient.cpp"
#include "doctor.cpp"

int main() {
    Patient p;
    Doctor d;

    int choice;

    do {
        cout << "Enter option 1 for patient\n";
        cout << "Enter option 2 for doctor\n";

        cin >> choice;

        switch (choice) {
            case 1: {
                cout << "***Patient***\n";
                p.doPatientRelatedWork();
                break; 
            }
            case 2: {
                cout << "***Doctor***\n";
                d.doDoctorRelatedWork();
                break; 
            }
            default:
                cout << "Invalid input!\n"; 
                break;
        }
    } while (choice == 1 | choice == 2);

    return 0;
}