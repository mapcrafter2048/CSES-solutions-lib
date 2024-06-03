#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    multiset<int> tickets;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        tickets.insert(x);
    }
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        auto it = tickets.upper_bound(x);
        if (it == tickets.begin()) {
            cout << -1 << endl;
        } else {
            it--;
            cout << *it << endl;
            tickets.erase(it);
        }
    }

    return 0;
}
