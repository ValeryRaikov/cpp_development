#include <iostream>
#include <string>

using namespace std;

class Line {
private:
    int Len;

public:
    Line(int length) : Len(length) {
        drawLine();
    }

    ~Line() {
        eraseLine();
    }

    void drawLine() const {
        for (int i = 0; i < Len; i++) {
            cout << "*";
        }
        cout << endl;
    }

    void eraseLine() const {
        for (int i = 0; i < Len; i++) {
            cout << "\b \b"; 
        }
        cout << endl;
    }
};

int main() {
    int length;
    cout << "Enter line length: ";
    cin >> length;

    Line line(length);

    return 0;
}
