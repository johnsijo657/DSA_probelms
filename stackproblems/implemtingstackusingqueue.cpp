#include <queue>
#include <iostream>

using namespace std;

class MyStack {
private:
    queue<int> q1, q2;

public:
    MyStack() {}

    void push(int x) {
        q2.push(x);

        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }

        swap(q1, q2);
    }

    int pop() {
        if (q1.empty()) {
            cout << "Stack is empty" << endl;
            return -1;
        }
        int topElement = q1.front();
        q1.pop();
        return topElement;
    }

    int top() {
        if (q1.empty()) {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return q1.front();
    }

    bool empty() {
        return q1.empty();
    }
};

int main() {
    MyStack myStack;

    myStack.push(1);
    myStack.push(2);
    cout << "Top element: " << myStack.top() << endl; // Output: 2
    cout << "Popped element: " << myStack.pop() << endl; // Output: 2
    cout << "Is stack empty: " << myStack.empty() << endl; // Output: false

    return 0;
}
