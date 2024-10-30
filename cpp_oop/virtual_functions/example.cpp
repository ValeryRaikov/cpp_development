#include <iostream>

using namespace std;

class Instrument {
public:
    virtual void makeSound() {
        cout << "Instrument is playing!" << endl;
    }
};

class Accordion: public Instrument {
public:
    void makeSound() {
        cout << "Accordion is playing!" << endl;
    }
};

class Piano: public Instrument {};

int main() {
    Instrument* i1 = new Accordion();
    i1->makeSound();

    Instrument* i2 = new Piano();
    i2->makeSound();

    return 0;
}