#include <iostream>

using namespace std;

class Distance {
protected:
	double distance;
public:
	Distance(double distance) {
		this->distance = distance;
	}

	double getDistance() const { return distance; }
	void setDistance(double value) {
		if (value > 0) {
			distance = value;
		}
	}

	virtual void convertDistance() const = 0;
};

class Kilometers : public Distance {
public:
	Kilometers(double distance) : Distance(distance) {};

	void convertDistance() const override {
		double kilometers = getDistance() * 1.6;

		cout << "Distance in kilometers: " << kilometers << endl;
	}
};

class Miles : public Distance {
public:
	Miles(double distance) : Distance(distance) {};

	void convertDistance() const override {
		double miles = getDistance() / 1.6;

		cout << "Distance in miles: " << miles << endl;
	}
};

int main() {
	Kilometers k(20.5); // distance in miles
	cout << "Distance in miles: " << k.getDistance() << endl;
	k.convertDistance();

	Miles m(100); // distance in kilometers
	cout << "Distance in kilometers: " << m.getDistance() << endl;
	m.convertDistance();

	return 0;
}