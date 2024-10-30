#include <iostream>

using namespace std;

class Instrument {
public:
    virtual void makeSound() = 0;
};

class Accordion: public Instrument {
public:
    void makeSound() {
        cout << "Accordion is playing!" << endl;
    }
};

class Piano: public Instrument {
    void makeSound() {
        cout << "Piano is playing!" << endl;
    }
};

int main() {
    Instrument* i1 = new Accordion();
    // i1->makeSound();

    Instrument* i2 = new Piano();
    // i2->makeSound();

    Instrument* instruments[2] = {i1, i2};
    for (int i = 0; i < 2; i++) {
        instruments[i]->makeSound();
    } 

    return 0;
}