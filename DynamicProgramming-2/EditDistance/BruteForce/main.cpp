#include <cstring>
#include <iostream>
using namespace std;

int editDistance(string s1, string s2) {
    // Base Case
    if (s1.empty() == true || s2.empty() == true) {
        return max(s1.size(), s2.size());
    }

    // Recursive call
    if (s1[0] == s2[0]) {
        return editDistance(s1.substr(1), s2.substr(1));
    }

    // Insert
    int x {1 + editDistance(s1.substr(1), s2)};
    // Delete
    int y {1 + editDistance(s1, s2.substr(1))};
    // Replace
    int z {1 + editDistance(s1.substr(1), s2.substr(1))};

    return min(x, min(y, z));
}

int main() {
    string s1;
    string s2;

    cin >> s1;
    cin >> s2;

    cout << editDistance(s1, s2);
}
