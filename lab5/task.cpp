#include <string> 
#include <iostream>
#include <cstring>

using namespace std;

enum ZooLocs { ZOOANIMAL, BEAR, PANDA, ELEPHANT, TIGER };

static char* locTable[] = {
    "Whole zoo area",
    "North B1: brown area",
    "East B1, P area",
    "South B2: Elephant habitat",
    "West B3: Tiger enclosure"
};

class ZooAnimal {
    friend void print(ZooAnimal*);
public:
    ZooAnimal(char* s = "ZooAnimal");
    virtual ~ZooAnimal() { delete[] name; }
    void link(ZooAnimal*);
    virtual void print();
    virtual void isA();
protected:
    char* name;
    ZooAnimal* next;
};

class Bear : public ZooAnimal {
public:
    Bear(char* s = "Bear", ZooLocs loc = BEAR, char* sci = "Ursidae");
    ~Bear() { delete[] sciName; }
    void print();
    void isA();
protected:
    char* sciName;
    ZooLocs ZooArea;
};

class Panda : public Bear {
public:
    Panda(char*, int, char* s = "Panda", char* sci = "Ailuropoda Melanoleuca", ZooLocs loc = PANDA);
    ~Panda() { delete[] indName; }
    void print();
    void isA();
protected:
    char* indName;
    int cell;
};

class Elephant : public ZooAnimal {
public:
    Elephant(char* s = "Elephant", ZooLocs loc = ELEPHANT, double tuskLen = 0.0);
    void print();
    void isA();
protected:
    double tuskLength;
    ZooLocs ZooArea;
};

class Tiger : public ZooAnimal {
public:
    Tiger(char* s = "Tiger", ZooLocs loc = TIGER, int stripes = 0);
    void print();
    void isA();
protected:
    int stripeCount;
    ZooLocs ZooArea;
};

// ZooAnimal class implementation
ZooAnimal::ZooAnimal(char* s) : next(nullptr) {
    name = new char[strlen(s) + 1];
    strcpy(name, s);
}
void ZooAnimal::link(ZooAnimal* za) {
    za->next = next;
    next = za;
}
void ZooAnimal::isA() {
    cout << "Animal name: " << name << '\n';
}
void ZooAnimal::print() {
    isA();
}

// Bear class implementation
Bear::Bear(char* s, ZooLocs loc, char* sci) : ZooAnimal(s), ZooArea(loc) {
    sciName = new char[strlen(sci) + 1];
    strcpy(sciName, sci);
}
void Bear::isA() {
    ZooAnimal::isA();
    cout << "\tScientific name: \t" << sciName << '\n';
}
void Bear::print() {
    ZooAnimal::print();
    cout << "\tLocation: \t" << locTable[ZooArea] << '\n';
}

// Panda class implementation
Panda::Panda(char* nm, int room, char* s, char* sci, ZooLocs loc)
    : Bear(s, loc, sci), cell(room) {
    indName = new char[strlen(nm) + 1];
    strcpy(indName, nm);
}
void Panda::isA() {
    Bear::isA();
    cout << "\tNickname: \t" << indName << '\n';
}
void Panda::print() {
    Bear::print();
    cout << "\tCell Number: \t" << cell << '\n';
}

// Elephant class implementation
Elephant::Elephant(char* s, ZooLocs loc, double tuskLen)
    : ZooAnimal(s), ZooArea(loc), tuskLength(tuskLen) {}
void Elephant::isA() {
    ZooAnimal::isA();
    cout << "\tTusk Length: \t" << tuskLength << " meters\n";
}
void Elephant::print() {
    ZooAnimal::print();
    cout << "\tLocation: \t" << locTable[ZooArea] << '\n';
}

// Tiger class implementation
Tiger::Tiger(char* s, ZooLocs loc, int stripes)
    : ZooAnimal(s), ZooArea(loc), stripeCount(stripes) {}
void Tiger::isA() {
    ZooAnimal::isA();
    cout << "\tNumber of Stripes: \t" << stripeCount << '\n';
}
void Tiger::print() {
    ZooAnimal::print();
    cout << "\tLocation: \t" << locTable[ZooArea] << '\n';
}

// Print function for ZooAnimal
void print(ZooAnimal* pz) {
    while (pz) {
        pz->print();
        cout << '\n';
        pz = pz->next;
    }
}

// Global pointers and instances
ZooAnimal* headPtr = nullptr;
Panda yinYang("Yin Yang", 1001, "Big Panda");
Elephant dumbo("Dumbo", ELEPHANT, 2.5);
Tiger sherKhan("Sher Khan", TIGER, 80);
Bear yogi("Yogi Bear", BEAR, "Ursus cartoonus");

// Function to create a linked list of animals
ZooAnimal* makelist(ZooAnimal* ptr) {
    ptr = &yinYang;
    ptr->link(&dumbo);
    ptr->link(&sherKhan);
    ptr->link(&yogi);
    return ptr;
}

// Main function
int main() {
    cout << "Zoo Animals Virtual Function Example\n";
    headPtr = makelist(headPtr);
    print(headPtr);

    return 0;
}
