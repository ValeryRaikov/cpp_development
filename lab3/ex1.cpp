#include <iostream>
#include <stack>

using namespace std;

class Stack {
private:
    stack<char> customStack;
public:
    Stack() = default;

    void push(char ch) {
        customStack.push(ch);
    }

    void pop() {
        if (!customStack.empty()) {
            customStack.pop();
        }
    }

    void loadStack() {
        char startChar = 'a';
        for (char ch = startChar; ch <= (startChar + 25); ++ch) {
            customStack.push(ch);
        }
    }

    void loadStack(int upper) {
        while (!customStack.empty()) {
            customStack.pop();
        }

        char startChar = upper ? 'A' : 'a';
        for (char ch = startChar; ch <= (startChar + 25); ++ch) {
            customStack.push(ch);
        }
    }

    void printStack() {
        cout << "Stack is:\n";
        while (!customStack.empty()) {
            cout << customStack.top() << ", ";
            customStack.pop();
        }
        cout << endl;
    }
};

int main() {
    Stack st1;
    st1.loadStack(1);
    st1.printStack();

    Stack st2;
    st2.loadStack();
    st2.printStack();

    return 0;
}