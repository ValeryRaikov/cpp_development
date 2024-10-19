#include <iostream>

using namespace std;

void walk_iter(int steps);
void walk_recur(int steps);

int main() {
    walk_iter(10);
    walk_recur(10);

    return 0;
}

void walk_iter(int steps) {
    for (int i = 0; i < steps; ++i) {
        cout << "You take a step!\n";
    }
}

void walk_recur(int steps) {
    if (steps > 0) {
        cout << "You take a step!\n";
        walk_recur(steps - 1);
    }
}