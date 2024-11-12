#pragma once

#include <iostream>

using namespace std;

class Disease {
private:
    string diseaseName;
    string virusName;
public:
    void getDiseaseData() {
        cout << "Enter disease name: ";
        getline(cin, diseaseName);
        cout << "Enter virus name: ";
        getline(cin, virusName);
    }

    void showDiseaseData() {
        cout << "***Disease***" << "\nDisease Name: " << diseaseName << "\nVirus Name: " << virusName << endl;
    }
};

/* int main() {
    Disease d1;

    d1.getDiseaseData();
    d1.showDiseaseData();

    return 0;
} */