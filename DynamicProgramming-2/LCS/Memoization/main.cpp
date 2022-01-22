#include <iostream>
#include <string>

using namespace std;

int lcsHelper(string s, string t, int **output) {
    // Base Case
    if (s.empty() == true || t.empty() == true) {
        return 0;
    }

    int m {static_cast<int>(s.size())};
    int n {static_cast<int>(t.size())};

    if (output[m][n] != -1) {
        return output[m][n];
    }

    // Recusive Calls
    int ans;
    if (s[0] == t[0]) {
        ans = 1 + lcsHelper(s.substr(1), t.substr(1), output);
    }
    else {
        int a {lcsHelper(s.substr(1), t, output)};
        int b {lcsHelper(s, t.substr(1), output)};
        int c {lcsHelper(s.substr(1), t.substr(1), output)};

        ans = max(a, max(b, c));
    }
    
    // Save your calculation
    output[m][n] = ans; 

    return ans;
}

int lcs(string s, string t) {
    int m {static_cast<int>(s.size())};
    int n {static_cast<int>(t.size())};

    int **output {new int*[m + 1]};

    for (int i {0}; i <= m; ++i) {
        output[i] = new int[n + 1];
        for (int j {0}; j <= n; ++j) {
            output[i][j] = -1;
        }
    }

    int result {lcsHelper(s, t, output)};

    for (int i {0}; i <= m; ++i) {
        delete output[i];
    }

    return result;
}

int main() {
    string s, t;
    cin >> s >> t;

    cout << lcs(s, t) << endl;

    return 0;
}
