#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Static Allocation
    vector<int> v;

    // Dynamic Allocation
    vector<int> *p {new vector<int>()};
    
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    v[1] = 100;

    cout << v[0] << endl;
    cout << v[1] << endl;
    cout << v[2] << endl;

    cout << v.size() << endl;
    cout << v.at(2) << endl;

    v.pop_back();

    cout << v.capacity() << endl;

    return 0;
}
