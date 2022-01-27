#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void connectComponents(int **edges, int n, int sv, bool *visited, vector<int> &store) {
    visited[sv] = true;
    store.push_back(sv);

    for (int i {0}; i < n; ++i) {
        if (sv == i) {
            continue;
        }
        
        if (edges[sv][i] == 1 && !visited[i]) {
            connectComponents(edges, n, i, visited, store);
        }
    }
}

void DFS(int **edges, int n) {
    bool *visited {new bool[n]};

    for (int i {0}; i < n; ++i) {
        visited[i] = false;
    }

    vector<vector<int>> allComponents;

    for (int i {0}; i < n; ++i) {
        if (!visited[i]) {
            vector<int> store;
            connectComponents(edges, n, i, visited, store);

            if (!store.empty()) {
                sort(store.begin(), store.end());
                allComponents.push_back(store);
            }
        }
    }

    for (const auto &x : allComponents) {
        for (const auto &i : x) {
            cout << i << " ";
        }

        cout << endl;
    }

    delete [] visited;
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

    DFS(edges, n);

    for (int i {0}; i < n; ++i) {
        delete [] edges[i];
    }

    return 0;
}
