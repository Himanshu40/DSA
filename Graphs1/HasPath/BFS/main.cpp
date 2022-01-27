#include <iostream>
#include <queue>

using namespace std;

bool hasPath(int **edges, int n, int sv, int ev, bool *visited) {
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
                pendingNodes.push(i);
                visited[i] = true;

                if (i == ev) {
                    return true;
                }
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

    int sv, ev;

    cin >> sv >> ev;

    bool *visited {new bool[n]};

    for (int i {0}; i < n; ++i) {
        visited[i] = false;
    }

    cout << ((hasPath(edges, n, sv, ev, visited)) ? "true" : "false");

    delete [] visited;

    for (int i {0}; i < n; ++i) {
        delete [] edges[i];
    }

    return 0;
}
