#include <iostream>
#include <queue>

using namespace std;

void print(int **edges, int n, int sv, bool *visited) {
    queue<int> pendingNodes;
    pendingNodes.push(sv);
    visited[sv] = true;
    
    while (pendingNodes.empty() != true) {
        int temp {pendingNodes.front()};
        pendingNodes.pop();

        cout << temp << " ";

        for (int i {0}; i < n; ++i) {
            if (i == temp) {
                continue;
            }

            if (edges[temp][i] == 1 && !visited[i]) {
                pendingNodes.push(i);
                visited[i] = true;
            }
        }
    }    
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

    bool *visited {new bool[n]};

    for (int i {0}; i < n; ++i) {
        visited[i] = false;
    }

    print(edges, n, 0, visited);

    delete [] visited;

    for (int i {0}; i < n; ++i) {
        delete [] edges[i];
    }

    return 0;
}
