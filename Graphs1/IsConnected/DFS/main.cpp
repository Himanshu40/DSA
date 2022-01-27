#include <iostream>

using namespace std;

void isConnected(int **edges, int n, int sv, bool *visited) {
    visited[sv] = true;

    for (int i {0}; i < n; ++i) {
        if (sv == i) {
            continue;
        }
        
        if (edges[sv][i] == 1 && !visited[i]) {
            isConnected(edges, n, i, visited);
        }
    }
}

bool isConnected(int **edges, int n) {
    bool *visited {new bool[n]};

    for (int i {0}; i < n; ++i) {
        visited[i] = false;
    }

    isConnected(edges, n, 0, visited);
    
    bool check {true};

    for (int i {0}; i < n; ++i) {
        if (!visited[i]) {
            check = false;
            break;
        }
    }

    delete [] visited;
    return check;
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

    cout << (isConnected(edges, n) ? "true" : "false");

    for (int i {0}; i < n; ++i) {
        delete [] edges[i];
    }

    return 0;
}
