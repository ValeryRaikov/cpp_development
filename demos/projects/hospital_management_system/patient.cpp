#include <iostream>
#include <fstream>

#include "person.cpp"
#include "disease.cpp"

using namespace std;

class Patient: public Person {
private:
    int patientId;
    Disease disease;
    string appointmentDate;
    char patientFile[20] = "patientData.dat";
    char patientTempFile[20] = "patientTempData.dat";
public:
    void getPatientInformation() {
        cout << "Enter data for patient:\n";
        getPersonData();

        cin.ignore();
        cout << "Disease details:\n";
        disease.getDiseaseData();

        cout << "Appointment Date: ";
        getline(cin, appointmentDate);
    }

    void addPatient() {
        cout << "Patient ID: ";
        cin >> patientId;

        getPatientInformation();
        ofstream writePatientData(patientFile, ios::binary | ios::out | ios::app);

        writePatientData.write((char*)this, sizeof(Patient)); 
    }

    void showPatientData() {
        cout << "***Patient Data***\n";
        cout << "Patient ID: " << patientId << endl;
        showPersonData();
        disease.showDiseaseData();
        cout << "Appointment Date: " << appointmentDate << endl;
    }

    void readPatientDataFromFile() {
        ifstream readdatafromdatabase(patientFile, ios::binary | ios::in);

        while(!readdatafromdatabase.eof()) {
            if (readdatafromdatabase.read((char*)this, sizeof(Patient))) {
                showPatientData();
            }
        }
    }

    void dischargePatient() {
        int pId, flag = 0;

        cout << "Enter patient ID you want to delete: ";
        cin >> pId;

        ifstream ifpatient;
        ifpatient.open(patientFile, ios::in | ios::binary);

        ofstream ofpatient;
        ofpatient.open(patientTempFile, ios::out | ios::binary);

        while (!ifpatient.eof()) {
            ifpatient.read((char*)this, sizeof(Patient));

            if (ifpatient) {
                if (patientId == pId) {
                    flag = 1;
                } else {
                    ofpatient.write((char*)this, sizeof(Patient));
                }
            }
        }

        ifpatient.close();
        ofpatient.close();

        remove(patientFile);
        rename(patientTempFile, patientFile);

        if (flag == 1) {
            cout << "Successfully deleted patient!\n";
        } else {
            cout << "No patient with this ID found!\n";
        }
    }

    void editPatient() {
        int pId, pos, flag = 0;

        cout << "Enter patient ID you want to edit: ";
        cin >> pId;

        fstream fpatient;
        fpatient.open(patientFile, ios::binary | ios::in | ios::out);

        while (!fpatient.eof()) {
            pos = fpatient.tellg();
            fpatient.read((char*)this, sizeof(Patient));

            if (fpatient) {
                if (patientId == pId) {
                    flag = 1;

                    getPatientInformation();

                    fpatient.seekp(pos);

                    fpatient.write((char*)this, sizeof(Patient));

                    showPatientData();
                    break;
                } 
            }
        }

        fpatient.close();

        if (flag == 1) {
            cout << "Successfully eddited patient!\n";
        } else {
            cout << "No patient with this ID found!\n";
        }
    }

    void doPatientRelatedWork() {
        char flag;
        int choice;

        do {
            cout << "Enter option 1 to add patient\n";
            cout << "Enter option 2 to show all patient data\n";
            cout << "Enter option 3 to discharge patient\n";
            cout << "Enter option 4 to edit patient\n";
            cout << "Enter option 5 to exit program\n";

            cin >> choice;

            switch (choice) {
                case 1: {
                    do {
                        addPatient();
                        cout << "Add another patient? y for yes.. ";
                        cin >> flag;
                    } while (flag == 'y');
                    break;
                }
                case 2: {
                    readPatientDataFromFile();
                    break;
                }
                case 3: {
                    dischargePatient();
                    break;
                }
                case 4: {
                    editPatient();
                    break;
                }
                default:
                    cout << "Invalid input!\n"; 
                    break;
            }
        } while (choice == 1 | choice == 2 | choice == 3 | choice == 4);
    }
};

/* int main() {
    Patient p1;

    p1.doPatientRelatedWork();

    return 0;
} */