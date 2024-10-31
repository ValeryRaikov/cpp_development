#include <iostream>
#include <queue>

using namespace std;

class Queue {
private: 
    queue<char> customQueue;
public:
    Queue() = default;

    void push(char ch) {
        customQueue.push(ch);
    }

    void pop() {
        if (!customQueue.empty()) {
            customQueue.pop();
        }
    }

    void loadQueue() {
        char startChar = 'a';
        for (char ch = startChar; ch <= (startChar + 25); ++ch) {
            customQueue.push(ch);
        }
    }

    void loadQueue(int upper) {
        while (!customQueue.empty()) {
            customQueue.pop();
        }

        char startChar = upper ? 'A' : 'a';
        for (char ch = startChar; ch <= (startChar + 25); ++ch) {
            customQueue.push(ch);
        }
    }

    void printQueue() {
        cout << "Queue is:\n";
        while (!customQueue.empty()) {
            cout << customQueue.front() << ", ";
            customQueue.pop();
        }
        cout << endl;
    }
};

int main() {
    Queue q1;
    q1.loadQueue();
    q1.printQueue();

    return 0;
}