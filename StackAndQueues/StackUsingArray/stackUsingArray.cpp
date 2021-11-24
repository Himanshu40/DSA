#include <iostream>

class StackUsingArray {
    private:
        int *data;
        int nextIndex;
        int capacity;
    public:
        StackUsingArray(int totalSize);
        
        int size() const;
        bool isEmpty() const;

        void push(int value);
        int pop();
        int top() const;
};

StackUsingArray::StackUsingArray(int totalSize) 
    : data {new int[totalSize]}, capacity {totalSize}, nextIndex {0} {}

int StackUsingArray::size() const {
    return nextIndex;
}

bool StackUsingArray::isEmpty() const {
    return !nextIndex;
}

void StackUsingArray::push(int value) {
    if (nextIndex == capacity) {
        std::cout << "Stack is full" << std::endl;

        return;
    }

    data[nextIndex++] = value;
}

int StackUsingArray::pop() {
    if (isEmpty()) {
        std::cout << "Stack is empty" << std::endl;
        
        return -1;
    }
    
    return data[--nextIndex];
}

int StackUsingArray::top() const {
    if (isEmpty()) {
        std::cout << "Stack is empty" << std::endl;

        return -1;
    }

    return data[nextIndex - 1];
}

int main() {
    StackUsingArray obj1(5);

    obj1.push(10);
    obj1.push(20);
    obj1.push(30);
    obj1.push(40);
    obj1.push(50);
    obj1.push(60);

    std::cout << obj1.top() << std::endl;
    
    std::cout << obj1.pop() << std::endl;
    std::cout << obj1.pop() << std::endl;
    std::cout << obj1.pop() << std::endl;
    
    std::cout << obj1.size() << std::endl;
    std::cout << std::boolalpha << obj1.isEmpty() << std::endl;

    return 0;
}
