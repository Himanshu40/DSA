#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

string uniqueChar(string str) {
    if (str.empty()) {
        return str;
    }

    string temp;
    unordered_map<char, bool> seen;

    for (int i {0}; i < str.length(); ++i) {
        if (seen.count(str[i]) == 0) {
            seen[str[i]] = true;
            temp += str[i];
        }
    }

    return temp;
}

int main() {
    string str;
    cin >> str;
    cout << uniqueChar(str);

    return 0;
}
