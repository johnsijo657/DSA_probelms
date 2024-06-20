#include <iostream>
#include <vector>

class MyCircularQueue {
private:
    std::vector<int> data;
    int head;
    int tail;
    int size;
    int count;

public:
    MyCircularQueue(int k) {
        data.resize(k);
        size = k;
        head = -1;
        tail = -1;
        count = 0;
    }

    bool enQueue(int value) {
        if (isFull()) {
            return false;
        }
        if (isEmpty()) {
            head = 0;
        }
        tail = (tail + 1) % size;
        data[tail] = value;
        count++;
        return true;
    }

    bool deQueue() {
        if (isEmpty()) {
            return false;
        }
        if (head == tail) {
            head = -1;
            tail = -1;
        } else {
            head = (head + 1) % size;
        }
        count--;
        return true;
    }

    int Front() {
        if (isEmpty()) {
            return -1;
        }
        return data[head];
    }

    int Rear() {
        if (isEmpty()) {
            return -1;
        }
        return data[tail];
    }

    bool isEmpty() {
        return count == 0;
    }

    bool isFull() {
        return count == size;
    }
};

int main() {
    MyCircularQueue myCircularQueue(3);
    std::cout << myCircularQueue.enQueue(1) << std::endl;
    std::cout << myCircularQueue.enQueue(2) << std::endl;
    std::cout << myCircularQueue.enQueue(3) << std::endl;
    std::cout << myCircularQueue.enQueue(4) << std::endl;
    std::cout << myCircularQueue.Rear() << std::endl;
    std::cout << myCircularQueue.isFull() << std::endl;
    std::cout << myCircularQueue.deQueue() << std::endl;
    std::cout << myCircularQueue.enQueue(4) << std::endl;
    std::cout << myCircularQueue.Rear() << std::endl;

    return 0;
}
