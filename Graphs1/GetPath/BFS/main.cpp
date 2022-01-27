#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

vector<int> *getPath(int **edges, int n, int sv, int ev, bool *visited) {
    queue<int> pendingNodes;
    pendingNodes.push(sv);

    unordered_map<int, int> map;

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
                map[i] = temp;

                if (i == ev) {
                    vector<int> *store {new vector<int>()};
                    store->push_back(i);

                    while (map[i] != sv) {
                        store->push_back(map[i]);
                        i = map[i];
                    }

                    store->push_back(map[i]);
                    return store;
                }
            }
        }
    }

    return nullptr;    
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

    vector<int> *store {getPath(edges, n, sv, ev, visited)};

    if (store != nullptr) {
        for (auto const &x : *store) {
            cout << x << " ";
        }

        store->clear();
    }

    delete [] visited;

    for (int i {0}; i < n; ++i) {
        delete [] edges[i];
    }

    return 0;
}
