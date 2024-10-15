#include <iostream>

using namespace std;

void bake_pizza();
void bake_pizza(string topic);

int main() {
    bake_pizza();
    bake_pizza("pepperoni");

    return 0;
}

void bake_pizza() {
    cout << "Baking your pizza!" << endl;
}

void bake_pizza(string topic) {
    cout << "Baking your pizza with " << topic << "!" << endl;
}