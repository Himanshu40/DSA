#include <iostream>
#include <vector>

using namespace std;

vector<int> *getPath(int **edges, int n, int sv, int ev, bool *visited) {
    if (sv == ev) {
        vector<int> *store {new vector<int>()};
        store->push_back(ev);

        return store;
    }
    
    visited[sv] = true;

    for (int i {0}; i < n; ++i) {
        if (sv == i) {
            continue;
        }
        
        if (edges[sv][i] == 1 && !visited[i]) {
            vector<int> *store {getPath(edges, n, i, ev, visited)};

            if (store != nullptr) {
                store->push_back(sv);

                return store;
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

    int sv;
    int ev;

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
        delete edges[i];
    }

    return 0;
}
