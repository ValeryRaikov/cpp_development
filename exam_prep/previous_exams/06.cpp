/*
Да се състави абстрактен клас Лице на окръжност с член-данни радиус (число) и член-функции от тип сет 
(за задаване на радиуса) и от тип гет (за достъп до радиуса) и за изчисляване на лице на окръжност. 
Да се състави клас Окръжност с член функция за изчисляване на лице на окръжност. За изчисляване на лицето 
да се използва виртуална функция и формулата: S = pi * r^2. Да се състави главна функция, в която чрез 
обекти да се изчисляват лицата на 2 окръжности с произволни радиуси и се извежда радиуса на по-голямата от тях. 
*/

// 01
#include <iostream>

using namespace std;

const double PI = 3.1415;

class CircleArea {
protected:
	double radius;
public:
	CircleArea(double r) : radius(r) {};

	double getRadius() { return radius; }

	void setRadius(double value) {
		if (value > 0) {
			radius = value;
		}
	}

	virtual void calculateArea() = 0;
};

class Circle : public CircleArea {
public:
	Circle(double r) : CircleArea(r) {};

	void calculateArea() override {
		double area = PI * radius * radius;
		cout << "S = " << area << endl;
	}
};

int main() {
	Circle c1(10);
	cout << "Circle 1:\n";
	c1.calculateArea();

	Circle c2(15.75);
	cout << "Circle 2:\n";
	c2.calculateArea();
	
	if (c1.getRadius() > c2.getRadius()) {
		cout << "Circle 1 radius is bigger -> " << c1.getRadius() << endl;
	} else if (c1.getRadius() < c2.getRadius()) {
		cout << "Circle 2 radius is bigger -> " << c2.getRadius() << endl;
	} else {
		cout << "Equal radiuses -> " << c1.getRadius() << endl;
	}

	return 0;
}

// 02
#include <iostream>
#include <cmath>

using namespace std;

// Абстрактен клас за лице на окръжност
class CircleArea {
protected:
    double radius; // Радиус на окръжността

public:
    CircleArea() : radius(0.0) {} // Конструктор по подразбиране

    // Сетър за задаване на радиуса
    void setRadius(double r) {
        if (r > 0) {
            radius = r;
        } else {
            cout << "Radius must be positive!" << endl;
        }
    }

    // Гетър за достъп до радиуса
    double getRadius() const {
        return radius;
    }

    // Чиста виртуална функция за изчисляване на лицето
    virtual double calculateArea() const = 0;
};

// Клас за конкретна окръжност
class Circle : public CircleArea {
public:
    Circle(double r) {
        setRadius(r); // Задаваме радиуса чрез set функцията
    }

    // Презаписваме виртуалната функция за изчисляване на лицето
    double calculateArea() const override {
        return M_PI * radius * radius;
    }
};

int main() {
    // Въвеждане на радиусите на две окръжности
    double radius1, radius2;
    cout << "Enter radius of the first circle: ";
    cin >> radius1;
    cout << "Enter radius of the second circle: ";
    cin >> radius2;

    // Създаваме обекти за двете окръжности
    Circle circle1(radius1);
    Circle circle2(radius2);

    // Изчисляваме лицата
    double area1 = circle1.calculateArea();
    double area2 = circle2.calculateArea();

    // Извеждаме резултатите
    cout << "Circle 1: Radius = " << circle1.getRadius() << ", Area = " << area1 << endl;
    cout << "Circle 2: Radius = " << circle2.getRadius() << ", Area = " << area2 << endl;

    // Проверяваме коя окръжност е с по-голям радиус
    if (circle1.getRadius() > circle2.getRadius()) {
        cout << "The first circle has the larger radius: " << circle1.getRadius() << endl;
    } else if (circle2.getRadius() > circle1.getRadius()) {
        cout << "The second circle has the larger radius: " << circle2.getRadius() << endl;
    } else {
        cout << "Both circles have the same radius: " << circle1.getRadius() << endl;
    }

    return 0;
}