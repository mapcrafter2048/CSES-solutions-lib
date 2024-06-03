#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

int main() {
    long long int computers;
    long long int connections;
    cin >> computers >> connections;

    vector<vector<int>> adj(computers + 1);
    for (int i = 0; i < connections; i++) {
        int node1, node2;
        cin >> node1 >> node2;

        adj[node1].push_back(node2);
        adj[node2].push_back(node1);
    }

    queue<int> q;
    vector<long long int> distance(computers + 1, LLONG_MAX);
    vector<long long int> parent(computers + 1);

    distance[1] = 0;
    q.push(1);

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int i = 0; i < adj[node].size(); i++) {
            if (distance[adj[node][i]] == LLONG_MAX) {
                distance[adj[node][i]] = distance[node] + 1;
                parent[adj[node][i]] = node;
                q.push(adj[node][i]);
            }
        }
    }

    return 0;
}
