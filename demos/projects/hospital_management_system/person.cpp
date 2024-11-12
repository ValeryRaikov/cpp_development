#pragma once

#include <iostream>

using namespace std;

class Person {
private:
    int age;
    string name;
    string address;
    string email;
    string phoneNumber;
public:
    void getPersonData() {
        cout << "Enter age: ";
        cin >> age;
        cin.ignore();
        cout << "Enter name: ";
        getline(cin, name);
        cout << "Enter address: ";
        getline(cin, address);
        cout << "Enter email: ";
        cin >> email;
        cout << "Enter phone number: ";
        cin >> phoneNumber;
    }

    void showPersonData() {
        cout << "***Person***" << "\nAge: " << age << "\nName: " << name << "\nAddress: " << address << 
        "\nEmail: " << email << "\nPhone Number: " << phoneNumber << endl;
    }
};

/* int main() {
    Person p1;
    p1.getPersonData();
    p1.showPersonData();

    return 0;
} */