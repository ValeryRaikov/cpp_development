#include <iostream>
#include <ctime>

int main() {
    using namespace std;

    srand(time(NULL));

    int num = rand() % 10;

    cout << num << '\n';  

    return 0;
}