#include <iostream>

using namespace std;

enum motor { gas, electric, diesel };
enum steering { power, rack_pinion, manual };

class vehicle {
protected:
    int num_wheels;
    int range;

public:
    vehicle(int w, int r) : num_wheels(w), range(r) {}

    void showv() {
        cout << "Wheels: " << num_wheels << '\n';
        cout << "Range: " << range << '\n';
    }
};

class motorized : virtual public vehicle {
protected:
    motor mtr;

public:
    motorized(motor m, int w, int r) : vehicle(w, r), mtr(m) {}

    void showm() {
        cout << "Motor: ";
        switch (mtr) {
            case gas:
                cout << "Gas\n";
                break;
            case electric:
                cout << "Electric\n";
                break;
            case diesel:
                cout << "Diesel\n";
                break;
        }
    }
};

class road_use : virtual public vehicle {
protected:
    int passengers;

public:
    road_use(int p, int w, int r) : vehicle(w, r), passengers(p) {}

    void showr() {
        cout << "Passengers: " << passengers << '\n';
    }
};

class car : public motorized, public road_use {
    steering strng;

public:
    car(steering s, motor m, int p, int w, int r)
        : vehicle(w, r), motorized(m, w, r), road_use(p, w, r), strng(s) {}

    void show() {
        showv();
        showr();
        showm();
        cout << "Steering: ";
        switch (strng) {
            case power:
                cout << "Power\n";
                break;
            case rack_pinion:
                cout << "Rack and pinion\n";
                break;
            case manual:
                cout << "Manual\n";
                break;
        }
    }
};

int main() {
    car c(power, gas, 5, 4, 500);
    c.show();
    
    return 0;
}
