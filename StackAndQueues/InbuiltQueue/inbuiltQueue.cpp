#include <iostream>
#include <queue>

int main() {
    std::queue<int> q1;

    q1.push(10);
    q1.push(20);
    q1.push(30);
    q1.push(40);
    q1.push(50);

    std::cout << q1.front() << std::endl;
    q1.pop();
    std::cout << q1.front() << std::endl;

    std::cout << q1.size() << std::endl;
    std::cout << q1.empty() << std::endl;

    while (!q1.empty()) {
        std::cout << q1.front() << " ";
        q1.pop();
    }

    std::cout << std::endl;

    return 0;
}
