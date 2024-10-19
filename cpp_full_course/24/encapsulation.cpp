#include <iostream>

using namespace std;

class Stove {
    private:
        int temperature = 0;
    public:
        Stove(int temperature) {
            setTemperature(temperature);
        }

        int getTemperature() {
            return temperature;
        }

        void setTemperature(int value) {
            this->temperature = value;
        }
};

int main() {
    Stove stove;

    cout << "t= " << stove.getTemperature() << '\n';
    stove.setTemperature(15);
    cout << "t=" << stove.getTemperature() << '\n';

    return 0;
}