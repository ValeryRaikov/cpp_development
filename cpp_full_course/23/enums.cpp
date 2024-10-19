#include <iostream>

enum Day {
    Monday = 0,
    Tuesday = 1,
    Wednesday = 2,
    Thursday = 3,
    Friday = 4,
    Saturday = 5,
    Sunday = 6,
};

int main() {
    using namespace std;

    Day today = Monday;

    cout << today << '\n'; // 0

    return 0;
}