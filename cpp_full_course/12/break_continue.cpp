#include <iostream>

int main() {
    using namespace std;

    for (int i = 0; i < 20; ++i) {
        if (i == 10) {
            continue;
        } else if (i == 15) {
            break;
        }

        cout << i << '\n';
    }

    return 0;
}