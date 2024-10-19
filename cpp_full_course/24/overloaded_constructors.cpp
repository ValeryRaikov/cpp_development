#include <iostream>

using namespace std;

class Pizza {
    public:
        string topping1;
        string topping2;

    Pizza() {}

    Pizza(string topping1) {
        this->topping1 = topping1;
    }

    Pizza(string topping1, string topping2) {
        this->topping1 = topping1;
        this->topping2 = topping2;
    }

    void print_toppings() {
        cout << "Pizza with " << topping1 << ", " << topping2 << endl;
    }
};

int main() {
    Pizza pizza1("pepperoni");
    pizza1.print_toppings();

    Pizza pizza2("mushrooms", "peppers");
    pizza2.print_toppings();

    Pizza pizza3;
    pizza3.print_toppings();

    return 0;
}