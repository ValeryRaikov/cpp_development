#include <iostream>
#include <cmath>

int main() {
    using namespace std;

    double a, b, c;
    
    cout << "Enter side a: " << endl;
    cin >> a;

    cout << "Enter side b: " << endl;
    cin >> b;

    c = sqrt(pow(a, 2) + pow(b, 2));
    cout << "Side c: " << c << endl;

    return 0;
}