#include <iostream>

using namespace std;

class area {
protected:
    double dim1, dim2; // Dimensions of the figure

public:
    void setarea(double d1, double d2) {
        dim1 = d1;
        dim2 = d2;
    }

    void getdim(double& d1, double& d2) const {
        d1 = dim1;
        d2 = dim2;
    }

    virtual double getarea() = 0; // Pure virtual function
    virtual ~area() = default;   // Virtual destructor for polymorphism
};

class rectangle : public area {
public:
    double getarea() override {
        double d1, d2;
        getdim(d1, d2);
        return d1 * d2;
    }
};

class triangle : public area {
public:
    double getarea() override {
        double d1, d2;
        getdim(d1, d2);
        return 0.5 * d1 * d2;
    }
};

int main() {
    area* p; // Pointer to base class
    rectangle r;
    triangle t;

    r.setarea(3.3, 4.5);
    t.setarea(4.0, 5.0);

    p = &r;
    cout << "Rectangle has area: " << p->getarea() << '\n';

    p = &t;
    cout << "Triangle has area: " << p->getarea() << '\n';

    return 0;
}
