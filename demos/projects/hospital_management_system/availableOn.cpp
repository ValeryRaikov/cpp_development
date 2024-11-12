#include <iostream>
#include <unordered_map>

using namespace std;

class AvailableOn {
private:
    int workingDaysCount; 
    unordered_map<string, int> availableSchedule;
public:
    void getWhenAvailable() {
        cout << "Enter number of working days: ";
        cin >> workingDaysCount;

        for (int i = 0; i < workingDaysCount; i++) {
            string dayOfWeek;
            int shift;

            cout << "Enter day of week: ";
            cin >> dayOfWeek;
            cout << "Enter shift: ";
            cin >> shift;

            if (availableSchedule.find(dayOfWeek) != availableSchedule.end()) {
                cout << "Day already added, skipping.\n";
                continue;
            }

            availableSchedule[dayOfWeek] = shift;
        }
    }

    void showWhenAvailable() {
        cout << "***Available***" << "\nWorking Days: " << workingDaysCount << endl;
        cout << "Available Schedule:\n";

        for (auto it = availableSchedule.begin(); it != availableSchedule.end(); ++it) {
            cout << "Day of Week: " << it->first << ", Shift: " << it->second << endl;
        }
    }
};

/* int main() {
    AvailableOn a1;

    a1.getWhenAvailable();
    a1.showWhenAvailable();
    return 0;
} */