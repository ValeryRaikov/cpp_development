#include <iostream>
#include <math.h>

using namespace std;

class Homework;

class Triangle {
private:
    float a;
    float perimeter;
    float area;
public:
    void setA(float value) { 
        a = value; 
        perimeter = a * 3; // equaliteral triangle
        area = sqrt(3) * a * a / 4;
    }

    // friend void printResults(Triangle);
    friend class Homework;
};

/*
void printResults(Triangle triangle) {
    cout << "Perimeter: " << triangle.perimeter << endl;
    cout << "Area: " << triangle.area << endl;
};
*/

class Homework {
public:
    void printResults(Triangle triangle) {
        cout << "Perimeter: " << triangle.perimeter << endl;
        cout << "Area: " << triangle.area << endl;
    };
};

int main() {
    Triangle triangle;
    triangle.setA(3);    

    //printResults(triangle);

    Homework h;
    h.printResults(triangle);

    return 0;
}