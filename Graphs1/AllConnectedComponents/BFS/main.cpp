#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

void connectComponents(int **edges, int n, int sv, bool *visited, vector<int> &store) {
    store.push_back(sv);
    
    queue<int> pendingNodes;
    pendingNodes.push(sv);
    visited[sv] = true;
    
    while (pendingNodes.empty() != true) {
        int temp {pendingNodes.front()};
        pendingNodes.pop();

        for (int i {0}; i < n; ++i) {
            if (i == temp) {
                continue;
            }

            if (edges[temp][i] == 1 && !visited[i]) {
                store.push_back(i);
                pendingNodes.push(i);
                visited[i] = true;
            }
        }
    }    
}

void BFS(int **edges, int n) {
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

    BFS(edges, n);

    for (int i {0}; i < n; ++i) {
        delete [] edges[i];
    }

    return 0;
}
