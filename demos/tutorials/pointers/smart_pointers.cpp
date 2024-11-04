#include <iostream>
#include <memory>

using namespace std;

class MyClass {
public:
    MyClass() {
        cout << "Constructor!\n";
    }

    ~MyClass() {
        cout << "Destructor!\n";
    }
};

int main() {
    /*
    unique_ptr<int> unPtr = make_unique<int>(25);
    cout << unPtr << endl;
    cout << *unPtr << endl; 

    unique_ptr<int> unPtr2 = move(unPtr);
    cout << *unPtr2 << endl;
    cout << unPtr << endl; 
    */

    unique_ptr<MyClass> unPtr = make_unique<MyClass>();
    shared_ptr<MyClass> shPtr = make_shared<MyClass>();
    cout << "Shared count: " << shPtr.use_count() << endl;
    shared_ptr<MyClass> shPtr2 = shPtr;
    cout << "Shared count: " << shPtr.use_count() << endl;

    weak_ptr<int> weakPtr;
    {
        shared_ptr<int> shPtr3 = make_shared<int>(25);
        weakPtr = shPtr3;
    }

    return 0;
}