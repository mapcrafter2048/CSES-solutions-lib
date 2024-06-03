#include <iostream>
#include <vector>

using namespace std;

void dfs(int node, vector<bool> &visited, vector<vector<int>> &adj) {
    visited[node] = true;
    for (auto child : adj[node]) {
        if (!visited[child]) {
            dfs(child, visited, adj);
        }
    }
}

int main() {
    int cities, roads;
    cin >> cities >> roads;

    vector<vector<int>> adj(cities + 1);
    vector<bool> visited(cities + 1, false);
    vector<int> bridges;

    for (int i = 0; i < roads; i++) {
        int node1, node2;
        cin >> node1 >> node2;

        adj[node1].push_back(node2);
        adj[node2].push_back(node1);
    }

    for (int i = 1; i <= cities; i++) {
        if (!visited[i]) {
            bridges.push_back(i);
            dfs(i, visited, adj);
        }
    }

    cout << bridges.size() - 1 << endl;
    for (int i = 0; i < bridges.size() - 1; i++) {
        cout << bridges[i] << " " << bridges[i + 1] << endl;
    }

    return 0;
}
