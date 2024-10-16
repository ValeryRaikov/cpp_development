#include <iostream>

int main() {
    using namespace std;

    string foods[10];

    fill(foods, foods + 10, "pizza");
    
    for (string food: foods) {
        cout << food << '\n';
    }

    return 0;
}