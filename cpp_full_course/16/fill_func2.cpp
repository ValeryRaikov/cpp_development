#include <iostream>

int main() {
    using namespace std;

    string foods[5];
    string temp;
    int size = sizeof(foods) / sizeof(foods[0]);

    for (int i = 0; i < size; i++) {
        cout << "Enter a food or 'q' to quit #" << i + 1 << ": " ;
        getline(cin, temp);

        if (temp == "q") {
            break;
        }

        foods[i] = temp;
    }

    cout << '\n';
    for (int i = 0; !foods[i].empty(); i++) {
        cout << food << '\n';
    }

    return 0;
}