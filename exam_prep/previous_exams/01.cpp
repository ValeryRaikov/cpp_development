#include <iostream>
#include <iomanip> // За да покажем резултата с фиксиран брой знаци след запетаята

using namespace std;

// Абстрактен клас
class Temperature {
protected:
    double fahrenheit; // Температура във Фаренхайт
public:
    // Конструктор
    Temperature(double temp = 32.0) : fahrenheit(temp) {};

    // Сетър за Фаренхайт
    void setTemperature(double temp) {
        fahrenheit = temp;
    }

    // Гетър за Фаренхайт
    double getTemperature() const {
        return fahrenheit;
    }

    // Чиста виртуална функция
    virtual double convertToCelsius() const = 0;

    // Виртуален деструктор (не е необходим, но е сложен за демонстрация)
    virtual ~Temperature() {};
};

// Производен клас
class Celsius : public Temperature {
public:
    // Конструктор
    Celsius(double temp = 32.0) : Temperature(temp) {};

    // Реализация на метода за преобразуване
    double convertToCelsius() const override {
        return (5.0 / 9.0) * (fahrenheit - 32.0);
    }
};

int main() {
    // Създаваме обект от типа Celsius
    Celsius temp1(100.0); // Температура 100°F

    // Демонстрираме работата на функциите
    cout << fixed << setprecision(2);
    cout << "Temperature in Fahrenheit: " << temp1.getTemperature() << "F" << endl;
    cout << "Converted to Celsius: " << temp1.convertToCelsius() << "C" << endl;

    // Променяме температурата
    temp1.setTemperature(32.0); // 32°F
    cout << "\nAfter changing the temperature:\n";
    cout << "Temperature in Fahrenheit: " << temp1.getTemperature() << "F" << endl;
    cout << "Converted to Celsius: " << temp1.convertToCelsius() << "C" << endl;

    return 0;
}
