#include <iostream>

using namespace std;

class Human {
    public:
        string name;
        string occupation;
        int age;

        void eat() {
            cout << "This person is eating!\n";
        }

        void drink() {
            cout << "This person is drinking!\n";
        }
};

int main() {
    Human human_obj;
    human_obj.name = "Gosho";
    human_obj.occupation = "programmer";
    human_obj.age = 21;

    cout << "Human: " << human_obj.name << ", " << human_obj.occupation << ", " << human_obj.age << '\n';

    human_obj.eat();
    human_obj.drink();

    return 0;
}