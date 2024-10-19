#include <iostream>

using namespace std;

class Animal {
    public:
        bool alive = true;

    void eat() {
        cout << "Animal is eating!\n";
    }
};

class Dog : public Animal {
    public:

    void bark() {
        cout << "The dog barks!\n";
    }
};

class Cat : public Animal {
    public:

    void eat() {
        cout << "NOM NOM NOM!\n";
    }

    void meow() {
        cout << "The cat meows!\n";
    }
};

int main() {
    Dog dog;

    cout << dog.alive << '\n';
    dog.eat();
    dog.bark();

    Cat cat;
    cat.eat();
    cat.meow();

    return 0;
}