#include <iostream>

using namespace std;

class Point {
protected:
	int x;
	int y;
	char name;
public:
	Point() {
		cout << "Enter x coordinate: ";
		cin >> x;
		cout << "Enter y coordinate: ";
		cin >> y;
		cout << "Enter point name: ";
		cin >> name;
	}

	int getX() { return x; }
	int getY() { return y; }
	char getName() { return name; }
};

class Circle {
protected:
	Point center;
	int radius;
public:
	Circle() {
		cout << "Enter center data:\n";
		center = Point();
		cout << "Enter radius length: ";
		cin >> radius;
	}

	Point getCenter() { return center; }
	int getRadius() { return radius; }

	void display() {
		cout << "Circle Data:\n";
		cout << "Center coordinates: (" << center.getX() << ", " << center.getY() << ")\n";
		cout << "Center name: " << center.getName() << endl;
		cout << "Radius length: " << getRadius() << endl;
	}
};

int main() {
	Circle circleArr[5] = {Circle(), Circle(), Circle(), Circle(), Circle()};

	cout << "Circles with radius length greater than 10:\n";
	for (auto& circle : circleArr) {
		if (circle.getRadius() > 10) {
			circle.display();
		}
	}

	return 0;
}