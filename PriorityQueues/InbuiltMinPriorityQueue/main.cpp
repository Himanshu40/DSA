#include <iostream>
#include <queue>

int main() {
    // min priority queue
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;

    pq.push(16);
    pq.push(1);
    pq.push(167);
    pq.push(7);
    pq.push(45);
    pq.push(36);

    std::cout << "Size: " << pq.size() << std::endl;
    std::cout << "Top: " << pq.top() << std::endl;

    while (!pq.empty()) {
        std::cout << pq.top() << std::endl;
        pq.pop();
    } 

    return 0;
}
