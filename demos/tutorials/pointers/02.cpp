#include <iostream>

using namespace std;

void printNumber(int* ptr) {
    cout << "Value is: " << *ptr << endl;
    cout << "Address is: " << ptr << endl;
}

void printLetter(char* ptr) {
    cout << "Letter is: " << *ptr << endl;
    cout << "Address is: " << ptr << endl;
}

void printData(void* ptr, char type) {
    switch (type) {
        case 'i':
            cout << *((int*)ptr) << endl;
            break;
        case 'c':
            cout << *((char*)ptr) << endl;
            break;
    }
}

int main() {
    int number = 5;
    char letter = 'a';

    // printNumber(&number);
    // printLetter(&letter);

    printData(&number, 'i');
    printData(&letter, 'c');

    return 0;
}