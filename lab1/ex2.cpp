#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Worker {
private:
    int socialNumber;
    string name;
    int yearsOfExperience;
    string currentPosition;
    vector<double> salaries;

public:
    Worker() : socialNumber(0), yearsOfExperience(0) {
        cout << "Enter current position: ";
        getline(cin, currentPosition);
    }

    Worker(int socialNum, string workerName, int experience, string position)
        : socialNumber(socialNum), name(workerName), yearsOfExperience(experience), currentPosition(position) {}

    void setSocialNumber(int socialNum) {
        socialNumber = socialNum;
    }

    int getSocialNumber() const {
        return socialNumber;
    }

    void setName(const string& workerName) {
        name = workerName;
    }

    string getName() const {
        return name;
    }

    void setYearsOfExperience(int experience) {
        yearsOfExperience = experience;
    }

    int getYearsOfExperience() const {
        return yearsOfExperience;
    }

    void setCurrentPosition(const string& position) {
        currentPosition = position;
    }

    string getCurrentPosition() const {
        return currentPosition;
    }

    void addSalary(double salary) {
        salaries.push_back(salary);
    }

    double calculateAverageSalary() const {
        if (salaries.empty()) {
            return 0.0;
        }

        double sum = 0;
        for (double salary : salaries) {
            sum += salary;
        }

        return sum / salaries.size();
    }

    double findMinSalary() const {
        if (salaries.empty()) {
            return 0.0;
        } 

        return *min_element(salaries.begin(), salaries.end());
    }
};

int main() {
    Worker worker1;
    worker1.setSocialNumber(12345);
    worker1.setName("Ivan Ivanov");
    worker1.setYearsOfExperience(5);
    worker1.setCurrentPosition("Software Developer");

    worker1.addSalary(2500.0);
    worker1.addSalary(2700.0);
    worker1.addSalary(3000.0);

    cout << "Person Data:\n";
    cout << "Name: " << worker1.getName() << endl;
    cout << "Social Number: " << worker1.getSocialNumber() << endl;
    cout << "Work Experience: " << worker1.getYearsOfExperience() << endl;
    cout << "Current Position: " << worker1.getCurrentPosition() << endl;
    cout << "Average Salary: " << worker1.calculateAverageSalary() << endl;
    cout << "Minimal Salary: " << worker1.findMinSalary() << endl;

    return 0;
}
