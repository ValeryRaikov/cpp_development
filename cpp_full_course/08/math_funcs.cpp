#include <iostream>
#include <cmath>

int main() {
    using namespace std;

    double x = 3;
    double y = 5;

    cout << max(x, y) << '\n';
    cout << min(x, y) << '\n';

    double z = pow(4, 3);
    cout << z << '\n';
    cout << sqrt(9) << '\n';
    cout << abs(-5) << '\n';
    cout << round(5.55) << ", " << ceil(5.55) << ", " << floor(5.55) << '\n';

    return 0;
}