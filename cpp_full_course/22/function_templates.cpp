#include <iostream>

using namespace std;

template <typename T, typename U>

auto max(T x, U y) {
    return (x > y) ? x : y;
}

int main() {
    cout << max(5, 10) << '\n';
    cout << max(5.5, 10.99) << '\n';
    cout << max('a', 'z') << '\n';
    cout << max(5, 10.25) << '\n';

    return 0;
}