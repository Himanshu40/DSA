#include <cstring>
#include <iostream>
using namespace std;

int editDistance(string s1, string s2, int **output) {
	int m {static_cast<int>(s1.size())};
    int n {static_cast<int>(s2.size())};
    
    // Base Case
    if (s1.empty() == true || s2.empty() == true) {
        return max(s1.size(), s2.size());
    }

    if (output[m][n] != -1) {
        return output[m][n];
    }

    int ans;
    // Recursive call
    if (s1[0] == s2[0]) {
        ans = editDistance(s1.substr(1), s2.substr(1), output);
    }
    else {
        // Insert
        int x {1 + editDistance(s1.substr(1), s2, output)};
        // Delete
        int y {1 + editDistance(s1, s2.substr(1), output)};
        // Replace
        int z {1 + editDistance(s1.substr(1), s2.substr(1), output)};

        ans = min(x, min(y, z));
    }

    output[m][n] = ans;

    return output[m][n];
}

int editDistance(string s1, string s2) {
    int m {static_cast<int>(s1.size())};
    int n {static_cast<int>(s2.size())};
    
    int **output {new int*[m + 1]};

    for (int i {0}; i <= m; ++i) {
        output[i] = new int[n + 1];
        for (int j {0}; j <= n; ++j) {
            output[i][j] = -1;
        }
    }

    int result {editDistance(s1, s2, output)};

    for (int i {0}; i <= m; ++i) {
        delete output[i];
    }

    return result;
}

int main() {
    string s1;
    string s2;

    cin >> s1;
    cin >> s2;

    cout << editDistance(s1, s2);
}
