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
    queue<long long int> q;

    for (long long int i = 1; i <= n; i++) {
        q.push(i);
    }

    bool flag = false;

    while (!q.empty()) {
        int element = q.front();
        q.pop();

        if (flag) {
            cout << element << " ";
        } else {
            q.push(element);
        }

        flag = !flag;
    }

    return 0;
}