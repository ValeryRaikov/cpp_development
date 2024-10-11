#include <iostream>

int main() {
    using namespace std;

    string name = "Valery";

    cout << name.length() << endl;
    cout << name.empty() << endl;

    name.append(" Raikov");
    cout << name << endl;

    cout << name.at(0) << endl;
    cout << name.insert(0, "@") << endl;
    cout << name.find(' ') << endl;
    cout << name.erase(0, 3) << endl;

    name.clear();
    cout << name << endl;

    return 0;
}