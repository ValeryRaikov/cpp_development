#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <ctime>
#include <map>
#include <limits>
#include <sys/stat.h>
#include <algorithm>

using namespace std;

class Date {
private:
    int day;
    int month;
    int year;
public:
    // Конструктор по подразбиране, който създава датата "01.01.2000";
    Date() {
        day = 1;
        month = 1;
        year = 2000;
    }

    // Параметризиран конструктор, който създава дата по подадени от потребителя аргументи;
    Date(int day, int month, int year) {
        this->day = day;
        this->month = month;
        this->year = year;
    }

    // Гетър и сетър методи за член променливите на класа
    int getDay() const { return day; }
    void setDay(int d) { day = d; }

    int getMonth() const { return month; }
    void setMonth(int m) { month = m; }

    int getYear() const { return year; }
    void setYear(int y) { year = y; }

    // Предефиниране на оператора << за по-лесно извеждане на информация за класа Date
    friend ostream &operator<<(ostream &os, const Date &date) {
        os << "Date: " << date.getDay() << "/" << date.getMonth() << "/" << date.getYear() << endl;
        return os;
    }

    // Предефиниране на оператора >> за по-лесно въвеждане на обекти от класа Date
    friend istream &operator>>(istream &is, Date &date) {
        char slash;
        is >> date.day >> slash >> date.month >> slash >> date.year;
        return is;
    }

     // Метод за проверка дали датата е от последния месец
    bool isWithinLastMonth() const {
        time_t t = time(nullptr);
        tm *today = localtime(&t);
        
        // Обект от тип Дата за текущия ден
        Date current(today->tm_mday, today->tm_mon + 1, today->tm_year + 1900);
        
        // Пресмятане на разликата в месеците
        int yearDiff = current.getYear() - year;
        int monthDiff = current.getMonth() - month;

        // Проверка дали разликата е в текущия месец
        return (yearDiff == 0 && monthDiff < 1 && monthDiff >= 0) || (yearDiff == 1 && monthDiff == -11);
    }
};

class PatientVisit {
private:
    string name;
    string egn;
    string complaint;
    Date visitDate;
    vector<pair<string, string>> previousComplaints; // динамичен масив, който съдържа двойка(чифт) от типа <оплакване, диагноза>
    vector<string> medications;
public:
    // Конструктор по подразбиране за зареждане на файла
    PatientVisit() = default;

    // Параметризиран конструктор, който създава посещение по подадени от потребителя аргументи;
    PatientVisit(string name, string egn, string complaint, Date visitDate, vector<pair<string, string>> previousComplaints, vector<string> medications){
        this->name = name;
        this->egn = egn;
        this->complaint = complaint;
        this->visitDate = visitDate;
        this->previousComplaints = previousComplaints;
        this->medications = medications;
    }

    // Гетър и сетър методи за член променливите на класа
    string getName() const { return name; }
    void setName(string n) { name = n; }

    string getEgn() const { return egn; }
    void setEgn(string e) { egn = e; }

    string getComplaint() const { return complaint; }
    void setComplaint(string c) { complaint = c; }

    Date getVisitDate() const { return visitDate; }
    void setVisitDate(Date vd) { visitDate = vd; }

    vector<pair<string, string>> getPreviousComplaints() const { return previousComplaints; }

    vector<string> getMedications() const { return medications; }

    // Предефиниране на оператора << за по-лесно извеждане на информация за класа PatientVisit
    friend ostream &operator<<(ostream &os, const PatientVisit &visit) {
        os << "Name: " << visit.getName() << "\nEGN: " << visit.getEgn()
           << "\nComplaint: " << visit.getComplaint() << "\nVisit Date: " << visit.getVisitDate()
           << "\nPrevious Complaints and Diagnoses:\n";

        for (const auto &entry : visit.getPreviousComplaints()) {
            os << "  - Complaint: " << entry.first << ", Diagnosis: " << entry.second << "\n";
        }

        os << "Prescribed Medications: ";
        for (const auto &med : visit.getMedications()) {
            os << med << ", ";
        }
        os << "\n";

        return os;
    }

    // Предефиниране на оператора << за по-лесна работа с файлов поток от данни за извеждане на информация
    friend ofstream &operator<<(ofstream &ofs, const PatientVisit &visit) {
        ofs << visit.name << '\n' << visit.egn << '\n' << visit.complaint << '\n'
            << visit.visitDate << '\n';

        ofs << "Number of complaints: " << visit.previousComplaints.size() << '\n';
        for (const auto &entry : visit.previousComplaints) {
            ofs << "Complaint: " << entry.first << '\n' << "Diagnosis: " << entry.second << '\n';
        }

        ofs << "Number of medications: " << visit.medications.size() << '\n';
        for (const auto &med : visit.medications) {
            ofs << med << '\n';
        }

        return ofs;
    }

    // Предефиниране на оператора >> за по-лесна работа с файлов поток от данни за въвеждане на информация
    friend ifstream &operator>>(ifstream &ifs, PatientVisit &visit) {
        getline(ifs, visit.name);
        getline(ifs, visit.egn);
        getline(ifs, visit.complaint);

        ifs >> visit.visitDate;      
        ifs.ignore();

        size_t complaintsCount;
        ifs >> complaintsCount;
        ifs.ignore();
        visit.previousComplaints.clear();

        for (size_t i = 0; i < complaintsCount; ++i) {
            string complaint, diagnosis;
            getline(ifs, complaint);
            getline(ifs, diagnosis);
            visit.previousComplaints.emplace_back(complaint, diagnosis);
        }

        size_t medsCount;
        ifs >> medsCount;
        ifs.ignore();
        visit.medications.clear();
        
        for (size_t i = 0; i < medsCount; ++i) {
            string med;
            getline(ifs, med);
            visit.medications.push_back(med);
        }

        return ifs;
    }
};

// Метод за запазване на посещенията във файл
void saveVisitsToFile(const vector<PatientVisit> &visits, const string &filename) {
    ofstream file(filename);

    for (const auto &visit : visits) {
        file << visit << "----\n"; // Разделител за всяко посещение на пациент
    }

    file.close();
}

// Метод за извличане на посещенията от файла
vector<PatientVisit> loadVisitsFromFile(const string &filename) {
    vector<PatientVisit> visits;
    ifstream file(filename);
    PatientVisit visit;

    while (file >> visit) {
        visits.push_back(visit);
        file.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    file.close();

    return visits;
}

// Метод за проверка дали файла съществува
bool fileExists(const string &filename) {
    struct stat buffer;   
    return (stat(filename.c_str(), &buffer) == 0); // Проверка за съществуването на файла
}

// Метод за намиране на най-често срещаната диагноза
string findMostCommonDiagnosis(const vector<PatientVisit> &visits) {
    map<string, int> diagnosisCount;
    for (const auto &visit : visits) {
        for (const auto &complaint : visit.getPreviousComplaints()) {
            diagnosisCount[complaint.second]++;
        }
    }

    string mostCommonDiagnosis;
    int maxCount = 0;
    for (const auto &pair : diagnosisCount) {
        if (pair.second > maxCount) {
            maxCount = pair.second;
            mostCommonDiagnosis = pair.first;
        }
    }

    return mostCommonDiagnosis;
}

int main() {
    vector<PatientVisit> visits;

    // Проверка за съществуването на файла
    if (fileExists("visits.txt")) {
        cout << "Loading previous visits from file...\n";
        visits = loadVisitsFromFile("visits.txt");

        // Показване на съществуващи посещения
        cout << "Current visits loaded from file:\n";
        for (const auto &v : visits) {
            cout << v << endl;
        }
    } else {
        cout << "No previous visits found. Starting fresh.\n";
    }

    int option;
    do {
        cout << "\n--- Patient Visit Management ---\n";
        cout << "1. Add/Update Patient Visit\n";
        cout << "2. Delete Patient Visit\n";
        cout << "3. Report Patients Seen Last Month\n";
        cout << "4. Report Patients with Complaints\n";
        cout << "5. Find Most Common Diagnosis\n";
        cout << "6. Exit\n";
        cout << "Select an option: ";
        cin >> option;
        cin.ignore();

        switch (option) {
            case 1: { // Добавяне на пациентско посещение
                cout << "\n--- Add/Update Patient Visit ---\n";
                string name, egn, complaint;
                int day, month, year;
                vector<pair<string, string>> previousComplaints;
                vector<string> medications;

                cout << "Enter patient name: ";
                getline(cin, name);
                cout << "Enter EGN: ";
                getline(cin, egn);
                cout << "Enter complaint: ";
                getline(cin, complaint);
                cout << "Enter visit date (day month year): ";
                cin >> day >> month >> year;
                Date visitDate(day, month, year);

                int numPreviousComplaints;
                cout << "Enter number of previous complaints: ";
                cin >> numPreviousComplaints;
                cin.ignore();

                for (int i = 0; i < numPreviousComplaints; ++i) {
                    string prevComplaint, diagnosis;
                    cout << "Previous complaint #" << (i + 1) << ": ";
                    getline(cin, prevComplaint);
                    cout << "Diagnosis: ";
                    getline(cin, diagnosis);
                    previousComplaints.emplace_back(prevComplaint, diagnosis);
                }

                int numMedications;
                cout << "Enter number of medications: ";
                cin >> numMedications;
                cin.ignore();

                for (int i = 0; i < numMedications; ++i) {
                    string med;
                    cout << "Medication #" << (i + 1) << ": ";
                    getline(cin, med);
                    medications.push_back(med);
                }

                PatientVisit newVisit(name, egn, complaint, visitDate, previousComplaints, medications);

                // Ако пациента съществува се ъпдейтва вместо да се добавя наново
                bool patientExists = false;
                for (size_t i = 0; i < visits.size(); ++i) {
                    if (visits[i].getEgn() == egn) {
                        visits[i] = newVisit; // Замяна на старото посещение с ново
                        patientExists = true;
                        break;
                    }
                }

                if (!patientExists) {
                    visits.push_back(newVisit);
                }

                // Отново запазва посещенията
                saveVisitsToFile(visits, "visits.txt");

                // Показва всички посещения
                cout << "\nUpdated visits:\n";
                for (const auto &v : visits) {
                    cout << v << endl;
                }
                break;
            }

            case 2: { // Изтрива пациент
                cout << "\n--- Delete Patient Visit ---\n";
                string egn;
                cout << "Enter EGN of the patient to delete: ";
                getline(cin, egn);

                auto it = remove_if(visits.begin(), visits.end(), [&egn](const PatientVisit &visit) {
                    return visit.getEgn() == egn;
                });

                if (it != visits.end()) {
                    visits.erase(it, visits.end());
                    cout << "Patient visit with EGN " << egn << " has been deleted.\n";
                } else {
                    cout << "No patient found with EGN " << egn << ".\n";
                }

                // Отново запазва посещенията
                saveVisitsToFile(visits, "visits.txt");
                break;
            }

            case 3: { // Отчет за пациентите през последния месец
                cout << "\n--- Patients Seen Last Month ---\n";
                Date today;
                vector<PatientVisit> lastMonthVisits;

                for (const auto &visit : visits) {
                    if (visit.getVisitDate().isWithinLastMonth()) {
                        lastMonthVisits.push_back(visit);
                    }
                }

                if (lastMonthVisits.empty()) {
                    cout << "No patients were seen in the last month.\n";
                } else {
                    for (const auto &v : lastMonthVisits) {
                        cout << v << endl;
                    }
                }
                break;
            }

            case 4: { // Отчет за пациенти по дадено оплакване
                cout << "\n--- Patients with Complaints ---\n";
                string searchComplaint;
                cout << "Enter complaint to search for: ";
                getline(cin, searchComplaint);

                bool found = false;
                for (const auto &visit : visits) {
                    if (visit.getComplaint() == searchComplaint) {
                        cout << visit << endl;
                        found = true;
                    }
                }

                if (!found) {
                    cout << "No patients found with the complaint: " << searchComplaint << ".\n";
                }
                break;
            }

            case 5: { // Отчет за най-често срещаната диагноза
                cout << "\n--- Most Common Diagnosis ---\n";
                string mostCommonDiagnosis = findMostCommonDiagnosis(visits);
                cout << "The most common diagnosis is: " << mostCommonDiagnosis << "\n";
                break;
            }

            case 6: // Изход от програмата
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Invalid option. Please try again.\n";
                break;
        }
    } while (option != 6);

    return 0;
}