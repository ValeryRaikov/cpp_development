#include <iostream>

int main() {
    using namespace std;

    char op;
    double num1, num2, result;

    cout << "*******************CALCULATOR**********************" << '\n';
        cout << "Enter operator(+, -, *, /): " << '\n';
        cin >> op;

        cout << "Enter number 1: " << '\n';
        cin >> num1;

        cout << "Enter number 2: " << '\n';
        cin >> num2;

        switch (op)
        {
        case '+':
            result = num1 + num2;
            cout << "Result = " << result << '\n';
            break;
        case '-':
            result = num1 - num2;
            cout << "Result = " << result << '\n';
            break;
        case '*':
            result = num1 * num2;
            cout << "Result = " << result << '\n';
            break;
        case '/':
            result = num1 / num2;
            cout << "Result = " << result << '\n';
            break;
        default:
            cout << "Invalid operator!" << '\n';
            break;
        }
    cout << "****************************************************" << '\n';

    return 0;
}