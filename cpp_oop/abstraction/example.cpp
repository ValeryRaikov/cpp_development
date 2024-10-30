#include <iostream>

using namespace std;

class Smartphone {
public:
    virtual void takeSelfie() = 0; 
    virtual void makeCall() = 0; 
};

class Android: public Smartphone {
public:
    void takeSelfie() {
        cout << "Android took a selfie!\n";
    }

    void makeCall() {
        cout << "Android is calling!\n";
    }
};

class Iphone: public Smartphone {
public:
    void takeSelfie() {
        cout << "IPhone took a selfie!\n";
    }

    void makeCall() {
        cout << "Iphone is calling!\n";
    }
};

int main() {
    Smartphone* s1 = new Android();
    s1->takeSelfie();
    s1->makeCall();

    Smartphone* s2 = new Iphone();
    s2->takeSelfie();
    s2->makeCall();

    return 0;
}