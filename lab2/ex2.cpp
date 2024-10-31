#include <iostream>

using namespace std;

class truck;

class car {
    int passengers;
    int speed;
public:
    car(int p, int s) : passengers(p), speed(s) {}
    friend int sp_greater(car c, truck t);
    friend double travel_time(car c, int distance); 
};

class truck {
    int weight;
    int speed;
public:
    truck(int w, int s) : weight(w), speed(s) {}
    friend int sp_greater(car c, truck t);
    friend double travel_time(truck t, int distance);
};

int sp_greater(car c, truck t) {
    return c.speed - t.speed;
}

double travel_time(car c, int distance) {
    if (c.speed == 0) 
        return -1;

    return static_cast<double>(distance) / c.speed;
}

double travel_time(truck t, int distance) {
    if (t.speed == 0) 
        return -1; 
    return static_cast<double>(distance) / t.speed;
}

int main() {
    int t;
    car c1(6, 55), c2(2, 120);
    truck t1(10000, 55), t2(20000, 72);
    int distance = 100;

    cout << "Comparing c1 and t1:\n";
    t = sp_greater(c1, t1);
    if (t < 0) cout << "Truck is faster.\n";
    else if (t == 0) cout << "Car and truck speed is the same.\n";
    else cout << "Car is faster.\n";

    cout << "\nComparing c2 and t2:\n";
    t = sp_greater(c2, t2);
    if (t < 0) cout << "Truck is faster.\n";
    else if (t == 0) cout << "Car and truck speed is the same.\n";
    else cout << "Car is faster.\n";

    cout << "\nTravel time for distance of " << distance << " km:\n";
    cout << "Car c1 time: " << travel_time(c1, distance) << " hours\n";
    cout << "Truck t1 time: " << travel_time(t1, distance) << " hours\n";

    return 0;
}
