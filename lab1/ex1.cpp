#include <iostream>
#include <iomanip>

using namespace std;

class Time {
private:
    int hour;
    int minute;
    int second;

    bool isValidTime(int h, int m, int s) const {
        return (h >= 0 && h <= 23) && (m >= 0 && m <= 59) && (s >= 0 && s <= 59);
    }

public:
    Time(int h = 0, int m = 0, int s = 0) {
        if (isValidTime(h, m, s)) {
            hour = h;
            minute = m;
            second = s;
        } else {
            cout << "Invalid time provided. Setting to 00:00:00." << endl;
            hour = minute = second = 0;
        }
    }

    void setTime(int h, int m, int s) {
        if (isValidTime(h, m, s)) {
            hour = h;
            minute = m;
            second = s;
        } else {
            cout << "Invalid time provided. Time not set." << endl;
        }
    }

    void print24HourFormat() const {
        cout << setw(2) << setfill('0') << hour << ":"
             << setw(2) << setfill('0') << minute << ":"
             << setw(2) << setfill('0') << second << endl;
    }

    void print12HourFormat() const {
        int displayHour = hour % 12;
        if (displayHour == 0) displayHour = 12;
        string period = (hour >= 12) ? "PM" : "AM";

        cout << setw(2) << setfill('0') << displayHour << ":"
             << setw(2) << setfill('0') << minute << ":"
             << setw(2) << setfill('0') << second << " " << period << endl;
    }
};

int main() {
    Time t1(13, 24, 7);  
    cout << "24-hour format: ";
    t1.print24HourFormat();
    
    cout << "12-hour format: ";
    t1.print12HourFormat();

    Time t2;
    t2.setTime(9, 45, 30); 
    cout << "\nSet new time:\n";
    cout << "24-hour format: ";
    t2.print24HourFormat();
    
    cout << "12-hour format: ";
    t2.print12HourFormat();

    return 0;
}