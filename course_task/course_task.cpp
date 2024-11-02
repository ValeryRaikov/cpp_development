#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <ctime>
#include <map>
#include <limits>

using namespace std;

class Date {
private:
    int day, month, year;
public:
    Date() : day(1), month(1), year(1900) {}

    Date(int d, int m, int y) : day(d), month(m), year(y) {}

    int getDay() const { return day; }
    int getMonth() const { return month; }
    int getYear() const { return year; }

    void setDay(int d) { day = d; }
    void setMonth(int m) { month = m; }
    void setYear(int y) { year = y; }

    friend ostream &operator<<(ostream &os, const Date &date) {
        os << date.day << "/" << date.month << "/" << date.year;
        return os;
    }

    friend istream &operator>>(istream &is, Date &date) {
        char slash;
        is >> date.day >> slash >> date.month >> slash >> date.year;
        return is;
    }
};

class PatientVisit {
private:
    string EGN;
    string name;
    string complaint;
    Date visitDate;
    vector<pair<string, string>> previousComplaints; // pair<complaint, diagnosis>
    vector<string> medications;

public:
    PatientVisit(string egn, string n, string comp, Date date, vector<pair<string, string>> prevComp, vector<string> meds)
        : EGN(egn), name(n), complaint(comp), visitDate(date), previousComplaints(prevComp), medications(meds) {}

    // Constructor without arguments for file loading
    PatientVisit() = default;

    // Accessor methods
    string getEGN() const { return EGN; }
    string getName() const { return name; }
    string getComplaint() const { return complaint; }
    Date getVisitDate() const { return visitDate; }
    vector<pair<string, string>> getPreviousComplaints() const { return previousComplaints; }
    vector<string> getMedications() const { return medications; }

    // << operator overload for output
    friend ostream &operator<<(ostream &os, const PatientVisit &visit) {
        os << "EGN: " << visit.EGN << "\nName: " << visit.name
           << "\nComplaint: " << visit.complaint << "\nVisit Date: " << visit.visitDate
           << "\nPrevious Complaints and Diagnoses:\n";

        for (const auto &entry : visit.previousComplaints) {
            os << "  - Complaint: " << entry.first << ", Diagnosis: " << entry.second << "\n";
        }

        os << "Prescribed Medications: ";
        for (const auto &med : visit.medications) {
            os << med << ", ";
        }
        os << "\n";
        return os;
    }

    // Stream operator overloads for file I/O
    friend ofstream &operator<<(ofstream &ofs, const PatientVisit &visit) {
        ofs << visit.EGN << '\n' << visit.name << '\n' << visit.complaint << '\n'
            << visit.visitDate << '\n';
        ofs << visit.previousComplaints.size() << '\n';
        for (const auto &entry : visit.previousComplaints) {
            ofs << entry.first << '\n' << entry.second << '\n';
        }
        ofs << visit.medications.size() << '\n';
        for (const auto &med : visit.medications) {
            ofs << med << '\n';
        }
        return ofs;
    }

    friend ifstream &operator>>(ifstream &ifs, PatientVisit &visit) {
        getline(ifs, visit.EGN);
        getline(ifs, visit.name);
        getline(ifs, visit.complaint);
        ifs >> visit.visitDate;
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

// Updated functions for saving and loading
void saveVisitsToFile(const vector<PatientVisit> &visits, const string &filename) {
    ofstream file(filename);
    for (const auto &visit : visits) {
        file << visit << "----\n"; // Separator for each patient visit
    }
    file.close();
}

vector<PatientVisit> loadVisitsFromFile(const string &filename) {
    vector<PatientVisit> visits;
    ifstream file(filename);
    PatientVisit visit;

    while (file >> visit) {
        visits.push_back(visit);
        // Skip the separator line after each entry
        file.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    file.close();
    return visits;
}

int main() {
    vector<PatientVisit> visits;

    // Add a sample visit
    Date visitDate(10, 10, 2023);
    vector<pair<string, string>> previousComplaints = {{"Headache", "Migraine"}, {"Dizziness", "Vertigo"}};
    vector<string> medications = {"Paracetamol", "Ibuprofen"};
    PatientVisit visit("1234567890", "John Doe", "Headache", visitDate, previousComplaints, medications);
    visits.push_back(visit);

    // Save to file
    saveVisitsToFile(visits, "visits.txt");

    // Load from file and print
    vector<PatientVisit> loadedVisits = loadVisitsFromFile("visits.txt");
    for (const auto &v : loadedVisits) {
        cout << v << endl;
    }

    return 0;
}
