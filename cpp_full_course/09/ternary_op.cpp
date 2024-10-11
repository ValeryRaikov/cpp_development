#include <iostream>

int main() {
    using namespace std;

    const int grade = 75;
    const int number = 10;

    grade >= 60 
        ? cout << "You pass!" << endl 
        : cout << "You fail!" << endl;

    number % 2 == 0
        ? cout << "Even" << endl
        : cout << "Odd" << endl;

    return 0;
}