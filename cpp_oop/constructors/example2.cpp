#include <iostream>

using namespace std;

class User {
public:
    string firstName;
    string lastName;
    int age;
    string email;

    User() {}

    User(string firstName, string lastName, int age, string email) {
        this->firstName = firstName;
        this->lastName = lastName;
        this->age = age;
        this->email = email;
    }

    static User initializeUser() {
        string fName, lName, email;
        int age;

        cout << "Enter first name: ";
        cin >> fName;
        cout << "Enter last name: ";
        cin >> lName;
        cout << "Enter age: ";
        cin >> age;
        cout << "Enter email: ";
        cin >> email;

        return User(fName, lName, age, email);
    }

    void printInfo() {
        cout << "User info:\n";
        cout << firstName << ' ' << lastName << ", " << age << ", " << email << endl;
    }

    ~User() { cout << "Destructing object!\n"; }
};

int main() {
    User u1;
    u1.printInfo();

    User u2 = User("Valery", "Raikov", 21, "vraikov@gmail.com");
    u2.printInfo();

    User u3 = User::initializeUser();
    u3.printInfo();
    
    return 0;
}