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

/*
 * so in this question we are finding the shortest path using bfs intially we
 * are setting the distance of all the nodes to infinity and then also keeping a
 * parent array to keep track of the parent of the node. then we are pushing the
 * source node in the queue and then we are traversing the graph and then we are
 * checking if the distance of the node is infinity then we are updating the
 * distance of the node and then we are pushing the node in the queue and then
 * we are updating the parent of the node. then we are checking if the distance
 * of the destination node is infinity then we are printing impossible else we
 * are printing the distance of the destination node and then we are printing
 * the path from the source to the destination node.
 */

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

    if (distance[computers] == LLONG_MAX) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        cout << distance[computers] + 1 << endl;
        vector<int> path;
        int node = computers;
        while (node != 1) {
            path.push_back(node);
            node = parent[node];
        }
        path.push_back(1);
        for (int i = path.size() - 1; i >= 0; i--) {
            cout << path[i] << " ";
        }
    }

    return 0;
}
