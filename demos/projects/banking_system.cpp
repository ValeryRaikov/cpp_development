#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class Person {
private:
    string name;
    string egn;
    int age;
    bool isMature;
public:
    Person() {}

    Person(string name, string egn, int age, bool isMature) {
        this->name = name;
        this->egn = egn;
        this->age = age;
        this->isMature = isMature;
    }

    string getName() {
        return name;
    }

    void setName(string value) {
        name = value;
    }

    string getEgn() {
        return egn;
    }

    void setEgn(string value) {
        egn = value;
    }

    int getAge() {
        return age;
    }

    void setAge(int value) {
        age = value;
    }

    bool getIsMature() {
        return isMature;
    }

    void setIsMature(bool value) {
        isMature = value;
    }

    void displayPersonInfo() {
        cout << "Person information:\n";
        cout << "Person: " << getName() << " with EGN: " << getEgn() << ", age: "
            << getAge() << ", status: " << (getIsMature() ? "mature" : "immature") << endl;
    }

    ~Person() {}
};

class BankAccount {
private:
    int accountNumber;
    Person accountHolder;
    double balance;
public:
    BankAccount(int accountNumber, Person accountHolder, double balance) {
        this->accountNumber = accountNumber;
        this->accountHolder = accountHolder;
        this->balance = balance;
    }

    int getAccountNumber() { 
        return accountNumber; 
    }

    void setAccountNumber(int value) {
        accountNumber = value;
    }

    Person getAccountHolder() {
        return accountHolder;
    }

    void setAccountHolder(Person value) {
        accountHolder = value;
    }

    double getBalance() {
        return balance;
    }

    void setBalance(double value) {
        balance = value;
    }

    virtual void deposit(double amount) {
        balance += amount;
    }

    virtual void withdraw(double amount) {
        balance -= amount;
    }

    virtual void displayAccountInfo() {
        cout << "Bank account:\n";
        cout << "Account number: " << getAccountNumber() << endl;
        getAccountHolder().displayPersonInfo();
        cout << "Account balance: " << getBalance() << endl;
    }

    virtual void applyMonthlyFee() = 0;

    virtual ~BankAccount() {}
};

class SavingsAccount: public BankAccount {
private:
    double interestRate;
public:
    SavingsAccount(int accountNumber, Person accountHolder, double balance, double interestRate)
    : BankAccount(accountNumber, accountHolder, balance), interestRate(interestRate) {}

    double getInterestRate() { 
        return interestRate; 
    }

    void setInterestRate(double value) {
        interestRate = value;
    }

    void applyMonthlyFee() {
        double monthlyFee = getBalance() * getInterestRate();

        if (!getAccountHolder().getIsMature()) {
            monthlyFee /= 2;
        }

        double newBalance = getBalance() - monthlyFee;

        setBalance(newBalance);
    }

    void withdraw(double amount) {
        if (getBalance() < 10000) {
            cout << "Card balance is below 10 000$. Cannot withdraw money!\n";
            return;
        }

        if (getBalance() < amount) {
            cout << "Card balance left money is below the desired amount of withdraw!\n";
            return;
        }

        setBalance(getBalance() - amount);
    }

    ~SavingsAccount() {}
};

class CheckingAccount: public BankAccount {
private:
    double overdraftLimit;
    double const montlyFeeCost = 4.99;
public:
    CheckingAccount(int accountNumber, Person accountHolder, double balance, double overdraftLimit)
    : BankAccount(accountNumber, accountHolder, balance), overdraftLimit(overdraftLimit) {}

    double getOverdraftLimit() {
        return overdraftLimit;
    }

    void setOverdraftLimit(double value) {
        overdraftLimit = value;
    }

    double getMonthlyFeeCost() const {
        return montlyFeeCost;
    }

    void applyMonthlyFee() {
        if (!getAccountHolder().getIsMature()) {
            setBalance(getBalance() - (getMonthlyFeeCost() / 2));
            return;
        }

        setBalance(getBalance() - getMonthlyFeeCost());
    }

    void withdraw(double amount) {
        if (getBalance() < 0 - getOverdraftLimit()) {
            cout << "Card alance is less than the provided overdraft limit. Cannot withdraw money!\n";
            return;
        }

        if (getBalance() - amount < 0 - getOverdraftLimit()) {
            cout << "Card balance left money is below the desired amount of withdraw!\n";
            return;
        }

        setBalance(getBalance() - amount);
    }

    ~CheckingAccount() {}
}; 

int main() {
    cout << "Welcome to the banking system. Choose option:\n";
    cout << "1. Create Person(account holder)\n";
    cout << "2. Create Bank account\n";
    cout << "3. Test Bank account functionality\n";
    cout << "4. Display information\n";
    cout << "5. Quit\n";

    vector<unique_ptr<Person>> persons;
    vector<unique_ptr<BankAccount>> accounts;

    int choice;
    do {
        cout << "Enter command: ";
        cin >> choice;

        if (choice < 0 || choice > 5) {
            cout << "Invalid choice!\n";
            continue;
        }

        switch (choice) {
            case 1: {
                string name, egn;
                int age;
                bool isMature;

                cout << "Enter name: ";
                cin >> name;
                cout << "Enter EGN: ";
                cin >> egn;
                cout << "Enter age: ";
                cin >> age;
                cout << "Is mature (1 for Yes, 0 for No): ";
                cin >> isMature;

                persons.push_back(make_unique<Person>(name, egn, age, isMature));
                cout << "Person created successfully.\n";
                break;
            }
            case 2: {
                if (persons.empty()) {
                    cout << "No person available. Create a person first.\n";
                    break;
                }

                int personIndex, accountNumber;
                double balance;
                int accountType;

                cout << "Choose account holder by index (0 - " << persons.size() - 1 << "): ";
                cin >> personIndex;
                if (personIndex < 0 || personIndex >= persons.size()) {
                    cout << "Invalid person index.\n";
                    break;
                }

                cout << "Enter account number: ";
                cin >> accountNumber;
                cout << "Enter initial balance: ";
                cin >> balance;
                cout << "Choose account type (1 for Savings, 2 for Checking): ";
                cin >> accountType;

                if (accountType == 1) {
                    double interestRate;
                    cout << "Enter interest rate for savings account: ";
                    cin >> interestRate;
                    accounts.push_back(make_unique<SavingsAccount>(accountNumber, *persons[personIndex], balance, interestRate));
                    cout << "Savings account created successfully.\n";
                } else if (accountType == 2) {
                    double overdraftLimit;
                    cout << "Enter overdraft limit for checking account: ";
                    cin >> overdraftLimit;
                    accounts.push_back(make_unique<CheckingAccount>(accountNumber, *persons[personIndex], balance, overdraftLimit));
                    cout << "Checking account created successfully.\n";
                } else {
                    cout << "Invalid account type.\n";
                }
                break;
            }
            case 3: {
                if (accounts.empty()) {
                    cout << "No accounts available. Create an account first.\n";
                    break;
                }

                int accountIndex;
                double amount;
                cout << "Choose account by index (0 - " << accounts.size() - 1 << "): ";
                cin >> accountIndex;
                if (accountIndex < 0 || accountIndex >= accounts.size()) {
                    cout << "Invalid account index.\n";
                    break;
                }

                cout << "Enter 1 to Deposit or 2 to Withdraw: ";
                int transactionType;
                cin >> transactionType;

                if (transactionType == 1) {
                    cout << "Enter deposit amount: ";
                    cin >> amount;
                    accounts[accountIndex]->deposit(amount);
                    cout << "Deposit successful.\n";
                } else if (transactionType == 2) {
                    cout << "Enter withdraw amount: ";
                    cin >> amount;
                    accounts[accountIndex]->withdraw(amount);
                } else {
                    cout << "Invalid transaction type.\n";
                }
                break;
            }
            case 4: {
                 cout << "\nPersons:\n";
                for (size_t i = 0; i < persons.size(); ++i) {
                    cout << "Person " << i << ":\n";
                    persons[i]->displayPersonInfo();
                }

                cout << "\nBank Accounts:\n";
                for (size_t i = 0; i < accounts.size(); ++i) {
                    cout << "Account " << i << ":\n";
                    accounts[i]->displayAccountInfo();
                }
                break;
            }
            case 5: {
                cout << "Exiting the program...\n";
                return -1;
            }
        }
    } while (choice != 5);

    return 0;
}