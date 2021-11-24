#include <iostream>
#include "dynamicQueue.h"

int main() {
    QueueUsingArray<int> q1(5);

    q1.enqueue(10);
    q1.enqueue(20);
    q1.enqueue(30);
    q1.enqueue(40);
    q1.enqueue(50);
    q1.enqueue(60);
    q1.enqueue(70);

    std::cout << q1.front() << std::endl;
    std::cout << q1.dequeue() << std::endl;
    std::cout << q1.dequeue() << std::endl;
    std::cout << q1.dequeue() << std::endl;
    std::cout << q1.front() << std::endl;


    std::cout << q1.getSize() << std::endl;
    std::cout << std::boolalpha << q1.isEmpty() << std::endl;

    return 0;
}
