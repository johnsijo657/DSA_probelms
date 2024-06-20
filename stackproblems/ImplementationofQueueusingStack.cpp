#include <iostream>
#include <stack>

class MyQueue {
private:
    std::stack<int> input;
    std::stack<int> output;

public:
    MyQueue() {}

    void push(int x) {
        input.push(x);
    }

    int pop() {
        if (output.empty()) {
            while (!input.empty()) {
                output.push(input.top());
                input.pop();
            }
        }
        int topElement = output.top();
        output.pop();
        return topElement;
    }

    int peek() {
        if (output.empty()) {
            while (!input.empty()) {
                output.push(input.top());
                input.pop();
            }
        }
        return output.top();
    }

    bool empty() {
        return input.empty() && output.empty();
    }
};

int main() {
    MyQueue myQueue;
    myQueue.push(1);
    myQueue.push(2);
    std::cout << "Peek: " << myQueue.peek() << std::endl; // return 1
    std::cout << "Pop: " << myQueue.pop() << std::endl; // return 1
    std::cout << "Empty: " << myQueue.empty() << std::endl; // return false
    return 0;
}
