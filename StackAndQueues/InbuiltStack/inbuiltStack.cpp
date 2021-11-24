#include <iostream>
#include <stack>

int main() {
    std::stack<int> s1;

    s1.push(10);
    s1.push(20);
    s1.push(30);
    s1.push(40);
    s1.push(50);

    std::cout << s1.top() << std::endl;
    s1.pop();
    std::cout << s1.top() << std::endl;

    std::cout << s1.empty() << std::endl;
    std::cout << s1.size() << std::endl;

    std::stack<int> s2;

    s2.push(110);
    s2.push(120);
    s2.push(130);
    s2.push(140);
    s2.push(150);
    
    s1.swap(s2);

    return 0;
}
