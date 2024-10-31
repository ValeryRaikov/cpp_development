#include <iostream>

using namespace std;

class Rectangle {
private:
    double width;
    double height;
public:
    Rectangle(double width, double height) {
        this->width = width;
        this->height = height;
    }

    double face() {
        return width * height;
    }

    void face(double &area, double &perimeter) {
        area = width * height;
        perimeter = 2 * (width + height);
    }

    void printInfo() {
        double area = face(); 
        cout << "Width: " << width << ", Height: " << height << endl;
        cout << "Area: " << area << endl;

        double perimeter;
        face(area, perimeter);
        cout << "Perimeter: " << perimeter << endl;
    }
};

int main() {
    Rectangle rect(5, 10);
    rect.printInfo();

    return 0;
}
