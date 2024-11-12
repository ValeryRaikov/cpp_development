#include <iostream>
#include <fstream>

#include "availableOn.cpp"
#include "disease.cpp"
#include "person.cpp"

using namespace std;

class Doctor: public Person {
private:
    int doctorId;
    Disease disease;
    AvailableOn available;
    char doctorFile[20] = "doctorData.dat";
    char doctorTempFile[20] = "doctorTempData.dat";
public:
    void getDoctorInformation() {
        cout << "Enter data for doctor:\n";
        getPersonData();

        cout << "Enter doctor ID: ";
        cin >> doctorId;

        cin.ignore();
        cout << "Enter name of disease specializations: ";
        disease.getDiseaseData();

        available.getWhenAvailable();
    }

    void showDoctorData() {
        cout << "\n\t***Doctor Data:***\n";
        showPersonData();

        cout << "Doctor ID is: " << doctorId << endl;
        disease.showDiseaseData();
        available.showWhenAvailable();

        cout << endl;
    }

    void addDoctorData() {
        getDoctorInformation();

        ofstream writeDoctorData(doctorFile, ios::binary | ios::out | ios::app);

        writeDoctorData.write((char*)this, sizeof(Doctor));
    }

    void readDoctorDataFromFile() {
        ifstream readdatafromdatabase(doctorFile, ios::binary | ios::in);

        while (!readdatafromdatabase.eof()) {
            if (readdatafromdatabase.read((char*)this, sizeof(Doctor))) {
                showPersonData();
            }
        }
    }

    void dischargeDoctor() {
        int dId, flag = 0;

        cout << "Enter doctor ID you want to delete: ";
        cin >> dId;

        ifstream ifdoctor;
        ifdoctor.open(doctorFile, ios::binary | ios::in);
        ofstream ofdoctor;
        ofdoctor.open(doctorFile, ios::binary | ios::out);

        while (!ifdoctor.eof()) {
            ifdoctor.read((char*)this, sizeof(Doctor));

            if (ifdoctor) {
                if (doctorId == dId) {
                    flag = 1;
                } else {
                    ofdoctor.write((char*)this, sizeof(Doctor));
                }
            }
        }

        ifdoctor.close();
        ofdoctor.close();

        remove(doctorFile);
        rename(doctorTempFile, doctorFile);

        if (flag == 1) {
            cout << "Successfully deleted doctor!\n";
        } else {
            cout << "No doctor with this ID found!\n";
        }
    }

    void editDoctor() {
        int dId, pos, flag = 0;

        cout << "Enter doctor ID you want to delete: ";
        cin >> dId;

        fstream fdoctor;
        fdoctor.open(doctorFile, ios::binary | ios::in | ios::out);

        while (!fdoctor.eof()) {
            pos = fdoctor.tellg();

            fdoctor.read((char*)this, sizeof(Doctor));

            if (fdoctor) {
                if (doctorId == dId) {
                    flag = 1;

                    getDoctorInformation();

                    fdoctor.seekp(pos);

                    fdoctor.write((char*)this, sizeof(Doctor));

                    showDoctorData();
                    break;
                }
            }
        }

        fdoctor.close();

        if (flag == 1) {
            cout << "Successfully eddited doctor!\n";
        } else {
            cout << "No doctor with this ID found!\n";
        }
    }

    void doDoctorRelatedWork() {
        char flag;
        int choice;

        do {
            cout << "Enter option 1 to add doctor\n";
            cout << "Enter option 2 to show all doctor data\n";
            cout << "Enter option 3 to discharge doctor\n";
            cout << "Enter option 4 to edit doctor\n";
            cout << "Enter option 5 to exit program\n";

            cin >> choice;

            switch (choice) {
                case 1: {
                    do {
                        addDoctorData();
                        cout << "Add another doctor? y for yes.. ";
                        cin >> flag;
                    } while (flag == 'y');
                    break;
                }
                case 2: {
                    readDoctorDataFromFile();
                    break;
                }
                case 3: {
                    dischargeDoctor();
                    break;
                }
                case 4: {
                    editDoctor();
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
    Doctor d1;

    d1.doDoctorRelatedWork();

    return 0;
} */