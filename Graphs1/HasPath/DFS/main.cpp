#include <iostream>

using namespace std;

bool hasPath(int **edges, int n, int sv, int ev, bool *visited) {
    if (sv == ev) {
        return true;
    }
    
    visited[sv] = true;

    for (int i {0}; i < n; ++i) {
        if (sv == i) {
            continue;
        }
        
        if (edges[sv][i] == 1 && !visited[i]) {
            if (hasPath(edges, n, i, ev, visited)) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    int n;
    int e;

    cin >> n >> e;

    int **edges {new int*[n]};

    for (int i {0}; i < n; ++i) {
        edges[i] = new int[n];

        for (int j {0}; j < n; ++j) {
            edges[i][j] = 0;
        }
    }

    for (int i {0}; i < e; ++i) {
        int f, s;
        cin >> f >> s;

        edges[f][s] = 1;
        edges[s][f] = 1;
    }

    int sv;
    int ev;

    cin >> sv >> ev;

    bool *visisted {new bool[n]};

    for (int i {0}; i < n; ++i) {
        visisted[i] = false;
    }

    cout << (hasPath(edges, n, sv, ev, visisted) ? "true" : "false");

    delete [] visisted;

    for (int i {0}; i < n; ++i) {
        delete edges[i];
    }

    return 0;
}
