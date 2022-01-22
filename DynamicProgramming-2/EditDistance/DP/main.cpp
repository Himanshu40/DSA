#include <cstring>
#include <iostream>

using namespace std;

int editDistance(string s1, string s2) {
    int m {static_cast<int>(s1.size())};
    int n {static_cast<int>(s2.size())};
    
    int **output {new int*[m + 1]};

    for (int i {0}; i <= m; ++i) {
        output[i] = new int[n + 1];
    }

    // 1st row
    for (int j {0}; j <= n; ++j) {
        output[0][j] = j;
    }

    // 1st col
    for (int i {0}; i <= m; ++i) {
        output[i][0] = i;
    }

    for (int i {1}; i <= m; ++i) {
        for (int j {1}; j <= m; ++j) {
            if (s1[m - i] == s2[n - j]) {
                output[i][j] = output[i - 1][j - 1];
            }
            else {
                // Insert
                int x {output[i - 1][j] + 1};
                // Delete
                int y {output[i][j - 1] + 1};
                // Replace
                int z {output[i - 1][j - 1] + 1};

                output[i][j] = min(x, min(y, z));
            }
        }
    }

    int result {output[m][n]};

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
