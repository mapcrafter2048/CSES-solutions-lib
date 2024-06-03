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
    long long int n;
    cin >> n;
    vector<pair<int, int>> times;
    for (int i = 0; i < n; i++) {
        int start, end;
        cin >> start >> end;
        times.push_back({start, 1});
        times.push_back({end, -1});
    }
    sort(times.begin(), times.end());

    int current = 0;
    int maxi = 0;
    for (auto time : times) {
        current += time.second;
        maxi = max(maxi, current);
    }
    cout << maxi << endl;
    return 0;
}