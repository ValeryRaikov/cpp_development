#include <iostream>
#include <ctime>

int main() {
    using namespace std;

    srand(time(0));

    int rand_num = rand() % 5 + 1;

    switch (rand_num)
    {
    case 1:
        cout << "Case 1" << endl; 
        break;
    case 2:
        cout << "Case 2" << endl; 
        break;
    case 3:
        cout << "Case 3" << endl; 
        break;
    case 4:
        cout << "Case 4" << endl; 
        break;
    case 5:
        cout << "Case 5" << endl; 
        break;
    }

    return 0;
}