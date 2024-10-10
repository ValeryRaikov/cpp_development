#include <iostream>

namespace first {
    int x = 5;
}

namespace second {
    double x = 7.55;
}

int main() {

    int x = 10;

    std::cout << first::x << ", " << second::x << ", " << x << std::endl;

    return 0;
}